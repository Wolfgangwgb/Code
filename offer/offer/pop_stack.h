#pragma once
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution9 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		if (pushV.size() != popV.size())
			return false;
		stack<int> s;//¸¨ÖúÕ»
		for (int i = 0,j=0; i < pushV.size();)
		{
			s.push(pushV[i++]);
			while (j < popV.size() && s.top() == popV[j])
			{
				s.pop();
				j++;
			}
		}
		return s.empty();
	}
};


void Test_popstack()
{
	Solution9 s;
	vector<int> v1;
	for (int i = 1; i < 6; i++)
		v1.push_back(i);
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(1);
	v2.push_back(2);

	if (s.IsPopOrder(v1, v2))
		cout << "Yes" << endl;
		else
		cout << "No" << endl;
}
