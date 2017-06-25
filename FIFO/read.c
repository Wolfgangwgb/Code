
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


#define _PATH_ "/home/wgb/Linux/FIFO_pipe/file.tmp"

int main()
{
	int fd = open(_PATH_,O_RDONLY);
	if(fd<0){
		perror("open");
		return 1;
	}
	char buf[1024];
	memset(buf,0,sizeof(buf));

	while(1)
	{
		ssize_t s = read(fd,buf,sizeof(buf));
		if(s<=0)
		{
			perror("read");
			return 2;
		}

		printf("read: %s\n",buf);

	}

	close(fd);
	return 0;
}
