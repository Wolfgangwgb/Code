
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

//管道
//特点：1.管道通信需要进程之间具有血缘关系
//		2.管道的生命周期---随进程
//		3.自带同步机制
//		4.面向字节流
//		5.单向通信
//		6.管道的读写端是通过文件描述符传递的
//管道的四种情况：1.写端都关闭，仍然有进程读数据，当剩余的数据读取
//					完之后，再次read返回0，就像读到了文件末尾；
//				  2.写端没有关闭，也没有向管道中写数据，进程从管道
//				  中读取数据，当剩余的数据读取完之后，再次read会阻
//				  塞，直到管道中有数据才读取并返回；
//				  3.读端都关闭，进程向管道中write，该进程就会收到
//				  SIGPIPE信号，通常会导致进程异常终止；
//				  4，读端没有关闭，也没有读数据，当进程把管道写满之
//				  后，会被阻塞，直到管道中有空余位置是继续写入；

int main()
{
	int fd[2];

	int sp = pipe(fd);
	if(sp != 0)
	{
		perror("pipe");
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
		close(fd[0]);//close read
		char buf[1024];
		while(1)
		{
			memset(buf,0,sizeof(buf));
			strcpy(buf,"hello wgb");
			write(fd[1],buf,sizeof(buf));
			sleep(2);
	    //	read(fd[1],buf,sizeof(buf));
	    //	sleep(2);
	    //	printf("%s\n",buf);

		}
	}
	else
	{
		//father
		close(fd[1]);//close write
		char buf1[1024];
		while(1)
		{
			memset(buf1,0,sizeof(buf1));
			read(fd[0],buf1,sizeof(buf1));
			printf("%s\n",buf1);
		//	strcpy(buf1,"sb wgb");
		//	write(fd[1],buf1,sizeof(buf1));
		}
	}
}

