#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>


void check(int *p)
{
	int i = 0;
	for(i=0; i<6; i++)
	{
		if(p[i]<60)
		{
			printf("%d  ",p[i]);
		}
	}
	printf("\n");
}

//void *malloc(unsigned int size)
//void *calloc(unsigned n,unsigned sise)
//void *realloc(void*p,unsigned int size)
//void free(void *p)
int main()
{
	int i,*p1,*p2;
	/*p1 = (int *) calloc(5,sizeof(int));*/       //malloc(5*sizeof(int))
    p1 = calloc(5,sizeof(int));      //p1位整形指针，自动切换
	p2 = realloc(p1,6*sizeof(int));       //重新分配p1（p1之前已用malloc 或 calloc分配动态空间）所指向的动态空间的大小
	for(i=0; i<6; i++)
	{
		scanf("%d",p1+i);
	}
	/*free(p2);*/     //释放指针变量p2所指向的动态空间
	check(p2);
	free(p2);
	system("pause");
	return 0;
}