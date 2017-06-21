#include <stdio.h>
#include <Windows.h>

//大端字节序和小端字节序
//低字节放在低地址---小端
//低字节放在搞地址---大端
//int check_big_little()
//{
//	int num = 1;
//	char *p = (char *)&num;
//	if(*p == 1)
//	{
//		return 1;
//	}
//	else 
//	{
//		return 0;
//	}
//}




//int main()
//{
//	int ret = 0;
//	ret = check_big_little();
//    if(ret == 1)
//	{
//		printf("little\n");
//	}
//	else
//	{
//		printf("big\n");
//	}
//	system("pause");
//	return 0;
//}





int check_big_little()
{
	union Bl
	{
		int i;             //i 和 c 公用一个地址
		char c;
	}bl;
	bl.i = 1;              // 当i = 1; 01 00 00 00   c:01
	return bl.c;
}

int main()
{
	char ret = check_big_little();
	if(ret == 1)
	{
		printf("little\n");
	}
	else
	{
		printf("big\n");
	}
	system("pause");
	return 0;
}