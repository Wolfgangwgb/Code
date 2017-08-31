#pragma once
#include<iostream>
using namespace std;

class Solution7 {
public:
	int  NumberOf1(int n) 
	{
		int count = 0;
		while (n)
		{
			count++;
			n =(n-1) & n;
		}
		return count;
	}
	int  NumberOf2(int n)
	{
		int count = 0;
		while (n)
		{
			if (n&1)
				count++;
			n >>=1;
		}
		return count;
	}
	int  NumberOf3(int n) {
		int falg = 1;
		int count = 0;
		while (falg){
			if (n&falg) count++;
			falg = falg << 1;
		}
		return count;
	}
};
void Test_one()
{
	Solution7 s;
	s.NumberOf1(7);
}