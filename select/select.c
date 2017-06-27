#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>


static int start_up(const char* _ip,int _port)//套接字初始化
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);
	if(bind(sock,(struct sockaddr*)&local,sizeof(local))< 0)
	{
		perror("bind");
		exit(2);
	}
	if(listen(sock,10)<0)
	{
		perror("listen");
		exit(3);
	}
	return sock;
}

void usage(const char* proc)
{
	printf("usage: %s [local_ip] [local_port]\n",proc);
}
int read_array[sizeof(fd_set)*8];
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}


	int listen_sock = start_up(argv[1],atoi(argv[2]));

	int i = 0;
	int arrlen = sizeof(read_array)/sizeof(read_array[0]);
	for(;i<arrlen;++i)//将read数组初始化为-1
	{
		read_array[i] = -1;
	}
	read_array[0] = listen_sock;//让监听套接字始终在数组0号位置


	while(1)
	{
	    fd_set read_set;
	    FD_ZERO(&read_set);//全部初始化为0
	    int max_fd = -1;//
		for(i=0;i<arrlen;++i)//设置有效的连接
		{
			if(read_array[i] == -1)
				continue;
			FD_SET(read_array[i],&read_set);////
			if(max_fd<read_array[i])
				max_fd = read_array[i];//改变最大值
		}

		struct timeval time = {1,0};
		int st = select(max_fd+1,&read_set,NULL,NULL,NULL);///??
		switch(st)
		{
			case 0://timeout
				printf("timeout...\n");
				break;
			case -1://error
				printf("select error\n");
				break;
			default://success
				{
					for(i=0;i<arrlen;++i)
					{
						if(read_array[i] < 0)
							continue;
						if(i==0 && FD_ISSET(listen_sock,&read_set))
						{
							//accept
							struct sockaddr_in client;
							socklen_t len = sizeof(client);
							int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
							if(new_sock<0)
							{
								perror("accept");
								return 2;
							}

							printf("get a client [%s:%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

							int j = 1;
							for(;j<arrlen;++j)
							{
								if(read_array[j]<0)
									break;
							}
							if(j == arrlen)
							{
								printf("read_set full\n");
								close(new_sock);
							}else
							{
								read_array[j] = new_sock;
							}
						}
						else if(i !=0 &&FD_ISSET(read_array[i],&read_set))
						{
							char buf[1024];
							ssize_t s = read(read_array[i],buf,sizeof(buf));
							if(s>0)
							{
								buf[s] = 0;
								printf("client#: %s\n",buf);
							}
							else if(s == 0)
							{
								printf("client quit..\n");
								close(read_array[i]);
								read_array[i] = -1;
							}
							else
							{
								printf("client error..\n");
								close(read_array[i]);
								read_array[i] = -1;
							}
						}
					}

				}
				break;
		}
	}
	return 0;
}
