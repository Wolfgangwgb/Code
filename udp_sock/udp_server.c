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

	struct sockaddr_in local;
	local.sin_family = PF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr =inet_addr(argv[1]);

	if(bind(sk,(struct sockaddr*)&local,sizeof(local))<0)
	{
		perror("bind");
		return 3;
	}

	while(1)
	{
		char buf[1024];
		struct sockaddr_in client;
		socklen_t len = sizeof(client);

		ssize_t s = recvfrom(sk,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
		if(s > 0)
		{
			buf[s] = 0;
			printf("client# %s\n",buf);
			sendto(sk,buf,strlen(buf),0,(struct sockaddr*)&client,len);
		}
		else
		{
			close(sk);
			printf("client quit...\n");
			break;
		}

	}







	return 0;
}
