#pragma once

#include<iostream>
#include<vector>
using namespace std;

//可以用位图解决
void FindNumsAppearOnce1(vector<int> data, int* num1, int* num2) 
{
	if (data.empty())
		return;
	int max = data[0];
	int i = 0;
	int min1 = 0;
	int min2 = 0;
	for (i = 1; i < data.size(); i++)
	{
		if (data[i]>max)
			max = data[i];
	}
	vector<int> v(max+1,0);//下标包括最大值，max+1
	for (i = 0; i < data.size(); i++)
	{
		v[data[i]]++;
	}
	*num1 = *num2 = 0;
	for (i = 1; i < v.size(); i++)
	{
		if (v[i] == 1&&min1==0)
		{
			min1 = i;
			*num1 = min1;
			continue;
		}
		else if (v[i] == 1 && min2 == 0)
		{
			min2 = i; 
			*num2 = min2;
			break;
		}
	}
}

unsigned int Findfirstbit1(int data)
{
	int index = 0;
	while ((data & 1) == 0 && index < (8 * sizeof(int)))
	{
		data >>= 1;
		index++;
	}
	return index;
}

bool Isbit1(int num, unsigned int bit)
{
	int index = 0;
	index = num >> bit;
	return index & 1;
}

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
{
	if (data.empty())
		return;
	int result = 0;
	for (int i = 0; i < data.size(); i++)//计算两个出现次数为1的数的异或的结果
	{
		result ^= data[i];
	}
	int bit = Findfirstbit1(result);//找到异或结果中第一个1的位置
	*num1 = *num2 = 0;
	for (int j = 0; j < data.size(); j++)
	{
		if (Isbit1(data[j], bit))
			*num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
}
//0000 0010--2
//0000 0011--3
//0000 0110--6
//0000 0011--3
//0000 0010--2

//0000 0101--5
//0000 0101--5
//0000 0100--4

void Test_arr_two_first()
{
	//2,4,3,6,3,2,5,5]
	vector<int> v;
	v.push_back(2);
    v.push_back(4);
	v.push_back(3); 
	v.push_back(6);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	int* p1 =&v[0];
	int* p2 =&v[1];
	//int p1 = 0, p2 = 0;
	FindNumsAppearOnce(v,p1,p2);
}
//4
//0000 0100
//6
//0000 0110
//0000 0010
//0000 0001

//2, 4, 3, 6, 3, 2, 5, 5


