#pragma once
#include<iostream>
#include<vector>
using namespace std;

//连续子数组的最大和
int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.empty())
		return 0;
	int cur = array[0];//当前连续最大和
	int max = array[0];//最大和值
	for (int i = 1; i < array.size(); i++)
	{
		cur += array[i];
		if (cur < array[i])//当前和值比i对应的元素值都小，将当前元素值赋给cur
			cur = array[i];//开始一个新的子数组
		if (cur>max)//当前值大于最大值，改变最大值
			max = cur;
	}
	return max;
}


void Test_subarray()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(-3);
	v.push_back(-2);
	v.push_back(7);
	v.push_back(-15);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	int ret = FindGreatestSumOfSubArray(v);
}