//5. 写一个函数返回参数二进制中 1 的个数
//比如： 15       0000 1111       4 个 1
//程序原型：
//int  count_one_bits(unsigned int value)
//{
//	// 返回 1的位数
//}
#include <stdio.h>
#include <Windows.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
    while(value)
	{
		if(value%2 == 1)        //
		{
			count++;
		}
		value = value/2;
	}
	return count;
}


int main()
{
	int ret = 0;
	unsigned int m = 0;
	scanf("%d",&m);
	ret = count_one_bits(m);
	printf("count = %d\n",ret);
	system("pause");
	return 0;
}