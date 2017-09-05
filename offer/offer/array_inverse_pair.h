#pragma once
#include<iostream>
#include<vector>
using namespace std;

int InversePairsCount(vector<int> &tmp, vector<int> &data, long start, long end)
{
	if (start == end)
	{
		return 0;
	}
	long length = (end - start) / 2;
	long left = InversePairsCount(data,tmp,start,start+length);
	long right = InversePairsCount(data, tmp, start+length+1, end);
	long count = 0;
	long i = start + length, j = end, temp = end;

	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			tmp[temp--] = data[i--];
			count += j - start - length;
			//count = count + j - (start + length + 1) + 1;
		}
		else
		{
			tmp[temp--] = data[j--];
		}
	}

	while (i >= start)
		tmp[temp--] = data[i--];
	while (j >= start + length + 1)
		tmp[temp--] = data[j--];
	return (left + right + count) % 1000000007;
}
int InversePairs(vector<int> &data) 
{
	if (data.empty())
		return 0;
	else if (data.size() == 1)
		return 1;
	else
	{
		vector<int> tmp(data);
		return InversePairsCount(tmp,data,0,data.size()-1);
	}
}



	

//1 2 3 4 5 6 7 0
void Test_array_inverse()
{
	vector<int> v;
	for (long i = 1; i<8; i++)
		v.push_back(i);
	v.push_back(0);
	long ret = InversePairs(v);
}