#pragma once
#include<iostream>
#include<vector>
using namespace std;

//O(N)
int GetNumberOfK(vector<int> data, int k)
{
	if (data.empty())
		return 0;
	int count = 0;
	vector<int>::iterator it = data.begin();
	while (*it != k){
		it++;
		if (it == data.end())//k有可能不存在
			return 0;
	}
	while (*it == k)
	{
		count++;
		it++;
	}
	return count;
}


void Test_GetNumberOfK()
{
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(3);
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
	int ret=GetNumberOfK(s,3);
}

