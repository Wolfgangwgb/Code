#pragma once
#include<iostream>
#include<stack>
using namespace std;
//实现一个栈Stack，要求实现Push（出栈）、Pop（入栈）、Min（返回最小值的操作）的时间复杂度为O(1) 

template <class T>
class Stack
{
public:
	Stack()
	{}

	void Push(const T& val)
	{
		sk.push(val);
		if (minsk.empty() || val < minsk.top())
			minsk.push(val);
	}

	void Pop()
	{
		if (sk.empty())
			return;
		if (sk.top() == minsk.top())
			minsk.pop();
		sk.pop();
	}

	T& Min()
	{
		if (!minsk.empty())
			return minsk.top();
	}

	size_t Size()
	{
		return sk.size();
	}

	T& Top()
	{
		return sk.top();
	}

	bool Empty()
	{
		return sk.empty();
	}

	~Stack()
	{}
private:
	stack<T> sk;
	stack<T> minsk;//辅助栈
};



void Testsk()
{
	Stack<int> s;
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	s.Push(2);
	s.Push(1);
	cout << s.Size() << endl;
	s.Pop();
	cout << s.Size() << endl;
	if (!s.Empty())
		cout <<s.Min() << endl;
}