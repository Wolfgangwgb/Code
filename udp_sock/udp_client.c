
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>




void usage(const char* proc)
{
	printf("usage:%s [local_ip] [local_port]\n",proc);
}

int main(int argc,char*argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}
	int sk = socket(AF_INET,SOCK_DGRAM,0);
	if(sk < 0)
	{
		perror("socket");
		return 2;
	}

	char buf[1024];
	struct sockaddr_in server;
	server.sin_family = PF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = inet_addr(argv[1]);

	socklen_t len = sizeof(server);

	while(1)
	{
		printf("Please Enter#:");
		fflush(stdout);

		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s > 0)
		{
			buf[s-1] = 0;
			sendto(sk,buf,sizeof(buf)-1,0,(struct sockaddr*)&server,len);

			s = recvfrom(sk,buf,sizeof(buf)-1,0,(struct sockaddr*)&server,&len);
			if(s>0)
			{
				buf[s] = 0;
				printf("server echo#: %s\n",buf);
			}
		}
	}
}

