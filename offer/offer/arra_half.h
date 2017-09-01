#pragma once
#include<iostream>
#include<vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.empty())
		return -1;
	int max = 0;//最大值
	int min = numbers.size() >> 1;//数组的一半
	vector<int>::iterator it = numbers.begin();
	while (it != numbers.end())//寻找最大值
	{
		if (*it > max)
			max = *it;
		it++;
	}
	vector<int> v(max+1,0);//辅助vector，初始化为0
	it = numbers.begin();
	while (it != numbers.end())//遍历原来vector，在辅助vector对应下标的数值++
	{
		v[*it++]++;
	}
	for (int i = 0; i < v.size(); i++)//遍历辅助vector，寻找出现次数最多的数，返回下标
	{
		if (v[i]>min)
			return i;
	}
	return 0;
}
//1, 2, 3, 2, 2, 2, 5, 4, 2
void Test_array_min()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);
	MoreThanHalfNum_Solution(v);
}