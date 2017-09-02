#pragma once
#include<iostream>
#include<set>
using namespace std;

//遍历寻找
int GetUglyNumber_Solution1(int index) 
{
	if (index < 1)
		return -1;
	int count = 0;
	int tmp = 0;
	for (int i = 1; i < INT_MAX; i++)
	{
		tmp = i;
		while (tmp % 2 == 0)
			tmp /= 2;
		while (tmp % 3 == 0)
			tmp /= 3;
		while (tmp % 5 == 0)
			tmp /= 5;
		if (tmp == 1)
			count++;
		else
			continue;

		if (count == index)
			return i;
	}
	return 0;
}

int Min(int a, int b, int c)
{
	int tmp = a < b ? a : b;
	return tmp < c ? tmp : c;
}
//思想：丑数是前面丑数乘以2/3/5的结果
//每次用前面的丑数乘以2、3、5取最小值放入数组
int GetUglyNumber_Solution2(int index)
{
	if (index < 1)
		return -1;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	int i = 1;
	int* array = new int[index+1];
	array[0] = 1;
	while (i<index)
	{
		int tmp = Min(array[index2]*2,array[index3]*3,array[index5]*5);
		if (tmp == array[index2] * 2)
			index2++;
		if (tmp == array[index3] * 3)
			index3++;
		if (tmp == array[index5] * 5)
			index5++;
		array[i++] = tmp;
	}
	int ret = array[index - 1];
	delete[] array;
	return ret;
}
//未完成
int GetUglyNumber_Solution(int index)
{
	if (index < 1)
		return 0;
	set<int> s;
	set<int>::iterator it = s.begin();
	s.insert(1);
	for (int i = 1; i < 100; i++)
	{	
		s.insert(i*2);
		s.insert(i*3);
		s.insert(i*5);
	}
	for (int i = 0; i < index; i++)
		it++;
	return *it;
}
void Test_ugly_number()
{
	for (int i = 0; i < 100; i++)
		cout << GetUglyNumber_Solution(i) << endl;

}