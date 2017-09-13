#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string ReverseSentence1(string str) 
{
	if (str.empty())
		return NULL;
	stack<string> s;
	string tmp;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		while (it != str.end()&&isspace(*it) == 0  )
		{
			tmp.push_back(*it);
			it++;
		}
		s.push(tmp);
		tmp.clear();
		if (it!=str.end())
			it++;
	}
	while (!s.empty())
	{
		tmp += s.top();
		s.pop();
		tmp.append(" ");
	}
	return tmp;
}
string ReverseSentence(string str)
{
	if (str.empty())
		return NULL;
	string tmp;
	string ret;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (isspace(*it) != 0)
		{
			ret = tmp +ret;
			if (it != str.end())
			{
				ret = " "+ret;
				it++;
			}
			tmp="";
		}
		tmp.push_back(*it);
		it++;
	}
	return tmp+ret;
}
void Test_ReverseSentence()
{
	string s = "student a am I";
	string ret=ReverseSentence(s);
}