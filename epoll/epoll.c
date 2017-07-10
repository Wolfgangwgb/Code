
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

#define _SIZE_ 256
#define _MAXEVENTS_ 1024



//1.非阻塞的收发接口
//2.将文件描述符设置为非阻塞(fcntl)
//3.

//总结：epoll服务器编写之时，如果采用ET模式，文件描述符必须设置为非阻塞；因为ET必须保证
//将该次数据一次性读完，只能轮询，轮询保证最后一次不被阻塞，所以套接字只能被设置为非阻塞。
static void usage(const char* proc)
{
	printf("usage:%s [local_ip][local_port]\n",proc);
}
static int start_up(const char* _ip,int _port)
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket");
		return 2;
	}

	int opt = 1;
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));


	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);
	socklen_t len = sizeof(local);
	if(bind(sock,(struct sockaddr*)&local,len)<0)
	{
		perror("bind");
		return 3;
	}
	if(listen(sock,10)<0)
	{
		perror("listen");
		return 4;
	}
	return sock;
}
int main(int argc,char*argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}

	int listen_sock = start_up(argv[1],atoi(argv[2]));

	int epfd = epoll_create(_SIZE_);
	if(epfd<0)
	{
		perror("epoll_create");
		return 5;
	}

    struct epoll_event ev;
    struct epoll_event	event[_MAXEVENTS_];
    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
	int ec = epoll_ctl(epfd,EPOLL_CTL_ADD,listen_sock,&ev);
	if(ec<0)
	{
		perror("epoll_ctl");
		return 6;
	}
	int timeout = -1;
	int nums = -1;
	while(1)
	{
	    int nums = epoll_wait(epfd,event,_MAXEVENTS_,timeout);
		switch(nums)
		{
			case 0:
				printf("timeout...\n");
				break;
			case -1:
				perror("epoll_ctl error");
				break;
			default:
				{
					//至少有一个事件就绪
		            int i = 0;
					for(i=0;i<nums;i++)
					{
						int sock = event[i].data.fd;
						
						if(sock == listen_sock && (event[i].events & EPOLLIN))//listen_sock
						{
							//accept
							struct sockaddr_in client;
							socklen_t len = sizeof(client);
							int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
							if(new_sock<0)
							{
								perror("accept");
								continue;
							}

							printf("get a client [%s:%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
							ev.events = EPOLLIN;
							ev.data.fd = new_sock;
	                        epoll_ctl(epfd,EPOLL_CTL_ADD,new_sock,&ev);

						}
						else if(sock != listen_sock)
						{
							if(event[i].events & EPOLLIN)
							{
								//read
								char buf[10240];
								ssize_t s = read(sock,buf,sizeof(buf));
								if(s>0)
								{
									printf("client:%s\n",buf);
									ev.events = EPOLLOUT;
									ev.data.fd = sock;
	                                epoll_ctl(epfd,EPOLL_CTL_MOD,sock,&ev);

								}else if(s ==0)
								{
									printf("client quit...\n");
									close(sock);
	                                epoll_ctl(epfd,EPOLL_CTL_DEL,sock,&ev);
								}else
								{
									
									perror("read error..\n");
									close(sock);
	                                epoll_ctl(epfd,EPOLL_CTL_DEL,sock,&ev);
								}
							}
							else if(event[i].events & EPOLLOUT)
							{
								//write
								const char* msg = "HTTP/1.1 OK 200\r\n\r\n<html><h1>hello world</h1></html>";
								write(sock,msg,strlen(msg));
								close(sock);
	                            epoll_ctl(epfd,EPOLL_CTL_DEL,sock,&ev);
							}
							else
							{}
						}
				}
		}

		break;
	   }
	}
return 0;
}
