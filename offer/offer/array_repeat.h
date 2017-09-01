#pragma once
#include<iostream>
#include<vector>
using namespace std;


bool duplicate(int numbers[], int length, int* duplication) 
{
	if (length <= 0)
		return false;
	int max = 0;
	int i = 0;
	for (i = 0; i < length; i++)//寻找数组中最大的值
	{
		if (numbers[i] > max)
			max = numbers[i];
	}
	vector<int> v(max+1,0);//辅助数组
	for (i = 0; i < length; i++)//将numbers中元素对应在vector中的下标的数++
	{
		v[numbers[i]]++;
	}

	for (i = 0; i < length; i++)//寻找出现次数超过1的
	{
		if (v[i]>1)
		{
			*duplication = i;
			return true;
		}
	}
	return false;
}



void Test_array_repeat()
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int j = 0;
	if (duplicate(array, sizeof(array) / sizeof(array[0]), &j))
		cout << "存在" << endl;
	else
		cout << "不存在" << endl;
}