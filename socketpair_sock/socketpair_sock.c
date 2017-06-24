#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>



int main()
{
	int fd[2];

	int sp = socketpair(PF_LOCAL,SOCK_STREAM,0,fd);
	if(sp != 0)
	{
		perror("socketpair");
		return 1;
	}

	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 2;
	}
	else if(id == 0)
	{
		// child
		close(fd[0]);
		char buf[1024];
		while(1)
		{
			memset(buf,0,sizeof(buf));
			strcpy(buf,"hello wgb");
			write(fd[1],buf,sizeof(buf));
			read(fd[1],buf,sizeof(buf));
			sleep(3);
			printf("%s\n",buf);

		}
	}
	else
	{
		//father
		close(fd[1]);
		char buf1[1024];
		while(1)
		{
			memset(buf1,0,sizeof(buf1));
			read(fd[0],buf1,sizeof(buf1));
			printf("%s\n",buf1);
			strcpy(buf1,"sb wgb");
			write(fd[0],buf1,sizeof(buf1));
		}
	}

	return 0;
}
