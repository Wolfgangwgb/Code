
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
void usage(const char* proc)
{
	printf("usage:%s [local_ip] [local_port]\n");
}


int main(int argc,char* argv[])
{

	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}
//	int fd = open("./log",O_WRONLY|O_CREAT,0664);
//	if(fd < 0)
//	{
//
//		return 1;
//	}
	int sk = socket(AF_INET,SOCK_STREAM,0);
	if(sk <0 )
	{
		perror("socket");
		return 1;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = inet_addr(argv[1]); 

	
	if(connect(sk,(struct sockaddr*)&server,sizeof(server))<0)
	{
		perror("connect");
		exit(1);
	}
	
	close(1);
//	int dp = dup2(sk,1);
    int dp = dup(sk);
	if(dp<0)
	{
		perror("dup");
		exit(2);
	}
	char buf[1024];
	while(1)
	{
	//	printf("Please Enter#:");
	//	fflush(stdout);

		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s > 0)
		{
			buf[s-1] = 0;
			printf("%s\n",buf);
			fflush(stdout);
	//		write(sk,buf,strlen(buf));
	//		s = read(sk,buf,sizeof(buf)-1);
	//		if(s > 0)
	//		{
	//			buf[s] = 0;
	//			printf("server echo# %s\n",buf);
	//		}
		}
	}

	return 0;
}
