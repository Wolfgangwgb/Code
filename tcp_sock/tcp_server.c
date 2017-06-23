#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<pthread.h>



static void usage(const char* proc)
{
	printf("usage: %s [local_ip] [local_port]\n",proc);
}

int start_up(const char* _ip,int _port)
{
	int sk = socket(AF_INET,SOCK_STREAM,0);
	if(sk < 0)
	{
		perror("socket");
		exit(2);
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;//泛型接口，底层需要区别
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);

	if(bind(sk,(struct sockaddr *)&local,sizeof(local)) < 0)
	{
		perror("bind");
		exit(3);
	}

	if(listen(sk,10) < 0)
	{
		perror("listen");
		exit(4);
	}
	return sk;
}
void* handlerquest(void*arg)
{
//	close(listen_sk);
	int new_sk = (int)arg;
	while(1)
	{
		char buf[1024];
		ssize_t s = read(new_sk,buf,sizeof(buf)-1);
		if(s > 0)
		{
			buf[s] = 0;
			printf("client:%s\n",buf);
			write(new_sk,buf,strlen(buf));
		}
		else
		{
			close(new_sk);
			printf("client quit ...\n");
			break;
    	}
	}
}


int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);//不会用打印手册
		return 1;
	}

	int listen_sk = start_up(argv[1],atoi(argv[2]));
	while(1)
	{
		struct sockaddr_in client;
		socklen_t len = sizeof(client);

		int new_sk = accept(listen_sk,(struct sockaddr*)(&client),&len);
		if(new_sk < 0)
		{
			perror("accept");
			continue;
		}

		printf("Get a new client %s : %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
//多线程
		pthread_t id;
		pthread_create(&id,NULL,handlerquest,(void*)new_sk);
		pthread_detach(id);

//多进程
	//	pid_t id = fork();

	//	if(id < 0)
	//	{
	//		close(new_sk);
	//	}
	//	else if(id == 0)
	//	{
	//		close(listen_sk);
	//		if(fork()<0)
	//		{
	//			exit(0);
	//		}

	//		while(1)
	//		{
	//			char buf[1024];
	//			ssize_t s = read(new_sk,buf,sizeof(buf)-1);
	//			if(s > 0)
	//			{
	//				buf[s] = 0;
	//				printf("client:%s\n",buf);
	//				write(new_sk,buf,strlen(buf));
	//			}
	//			else
	//			{
	//				close(new_sk);
	//				printf("client quit ...\n");
	//				break;
	//			}
	//		}
	//		close(new_sk);
	//	}
	//	else
	//	{
	//		close(new_sk);
	//	}



	//	while(1)
	//	{
	//		char buf[1024];
	//		ssize_t s = read(new_sk,buf,sizeof(buf)-1);
	//		if(s > 0)
	//		{
	//			buf[s] = 0;
	//			printf("client:%s\n",buf);
	//			write(new_sk,buf,strlen(buf));
	//		}
	//		else
	//		{
	//			close(new_sk);
	//			printf("client quit ...\n");
	//			break;
	//		}
	//	}

	}

	return 0;
}
