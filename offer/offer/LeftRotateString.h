#pragma once
#include<iostream>
#include<string>
using namespace std;

string LeftRotateString(string str, int n)
{
	if (str.empty())
		return "";
	string tmp = str;
	while (n--)
	{
		tmp.append(1, tmp[0]);
		tmp.erase(0, 1);
	}
	return tmp;
}

void Test_LeftRotateString()
{
	string  s = "abcXYZdef";
	string ret = LeftRotateString(s,3);
}