#pragma once
#include<iostream>
#include<string>
using namespace std;

int FirstNotRepeatingChar(string str)
{
	if (str.empty())
		return -1;
	int array[256] = { 0 };
	string::iterator it = str.begin();
	while (it != str.end())
	{
		array[*it]++;
		it++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (array[str[i]] == 1)
			return i;
	}
	return 0;
}


void Test_first_char()
{
	string s("avdcsgavdcg");
	int ret = FirstNotRepeatingChar(s);
}