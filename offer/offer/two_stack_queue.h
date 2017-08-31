#pragma once
#include<iostream>
#include<stack>
using namespace std;

class Solution1
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		int _pop = 0;
		if (stack1.empty())
		{
			return -1;
		}
		else if (stack1.size() == 1)
		{
			_pop = stack1.top();
			stack1.pop();
		}
		else
		{
			int i = 0;
			int len = stack1.size() - 1;
			for (i = 0; i < len; i++)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			_pop = stack1.top();
			stack1.pop();
			len = stack2.size();
			for (i = 0; i < len; i++)
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		return _pop;
	}

private:
	stack<int> stack1;//´æÊý
	stack<int> stack2;//¸¨Öú
};


class Solution2
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int tmp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		tmp = stack2.top();
		stack2.pop();
		return tmp;
	}

private:
	stack<int> stack1;//´æÊý
	stack<int> stack2;//¸¨Öú´æÊý
};

class Solution3
{
public:
	int cou = 0;
	void push(int node) {
		stack1.push_back(node);
		stack2.push_back(cou++);
	}

	int pop() {
		int i = 0;
		while (stack2[i] == -1)
		{
			i++;
		}
		stack2[i] = -1;
		return stack1[i];
	}

private:
	vector<int> stack1;//´æÊý
	vector<int> stack2;//µØÖ·
};

void Test_stack()
{
	Solution1 s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	s.push(4);
	cout << s.pop() << endl;
	s.push(5);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
}