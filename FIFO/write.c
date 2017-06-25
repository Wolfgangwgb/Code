
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define _PATH_ "/home/wgb/Linux/FIFO_pipe/file.tmp"

//命名管道(FIFO)
//与管道的区别：
//				1.管道只能用于具有血缘关系的进程间通信，FIFO克服了这一缺点
//				2.FIFO提供一个路径名与之关联，即使没有血缘关系的进程可以通过路径名访问
//				3.FIFO工作原则：先进先出
//				4.命名管道存储于硬盘
//
//命名管道的创建：1.mkfifo/mknod：mkond是比较老的函数，通常使用mkfifo
//				  2.注意umask対生成文件权限的影响
//创建过程：1.创建FIFO(mkfifo)
//			2.打开文件--open ---方式：O_WRNOLY:只写    O_RDNOLY：只读  O_RDWR:读写
//			3.使用：发送与接收数据

int main()
{
	int mf = mkfifo(_PATH_,0666|S_IFIFO);
	if(mf < 0)
	{
		perror("mkfifo");
		return 1;
	}

	int fd = open(_PATH_,O_WRONLY);
	if(fd < 0)
	{
		perror("open");
		return 2;
	}

	char buf[1024];
	memset(buf,0,sizeof(buf));

	while(1)
	{
		printf("Please Enter#:");
//		ssize_t s = read(0,buf,sizeof(buf));
		scanf("%s",buf);
		//if(s < 0)
	 //	{
	//		perror("read");
	//		return 3;
	//	}

		ssize_t ss = write(fd,buf,sizeof(buf));
		if(ss < 0)
		{
			perror("write");
			return 4;
		}

	}
	close(fd);

}
