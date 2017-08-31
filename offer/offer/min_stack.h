#pragma once
#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty())
			s2.push(value);
		else if (value < s2.top())
			s2.push(value);
	}
	void pop() {
		if (s1.top() == s2.top())//ºöÂÔÁË
			s2.pop();
		s1.pop();
	}
	int top() {
		return s1.top();
	}
	int min() {
		return s2.top();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

void Test_min_stack()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.min() << endl;
}