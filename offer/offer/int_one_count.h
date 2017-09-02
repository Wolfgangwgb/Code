#pragma once
#include<iostream>
using namespace std;
//默认从1-n的整数中的1的个数
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 1)
				count++;
			tmp /= 10;
		}
	}
	return count;
}
//从start到end之间的整数中1的个数
int NumberOf1Between1AndN_Solution(int start,int end)
{
	int count = 0;
	for (int i = start; i <= end; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 1)
				count++;
			tmp /= 10;
		}
	}
	return count;
}

void Test_int_one_count()
{
	int ret = NumberOf1Between1AndN_Solution(100,1300);
}