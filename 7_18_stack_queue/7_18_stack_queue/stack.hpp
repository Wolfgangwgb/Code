#pragma once
#include<iostream>
#include<stack>
using namespace std;
//两个栈实现一个队列


template <class T>
class Queue
{
public:
	Queue()
	{}
	void Push(const T& val)
	{
		s1.push(val);
	}
	void Pop()
	{
		//s2 not null
		//s2 null ,s1 not null
		//s1,s2 null
		/*if (s2.empty())
		{
			s2.pop();
		}
		else if (s2.empty() && !s1.empty())
		{
			Move(s1,s2);
			s2.pop();
		}
		*/
		if (s2.empty())
			Move(s1,s2);
		s2.pop();
	}

	size_t Size()
	{
		return s1.size() + s2.size();
	}
	bool Empty()
	{
		if ((s1.empty()) && (s2.empty()))
			return true;
		return false;
	}
	T& Front()
	{
		if (s1.empty())
			Move(s2, s1);
		return s1.top();
	}
	T& Back()
	{
		if (s2.empty())
			Move(s1, s2);
		return s2.top();
	}

	~Queue()
	{}
private:
	void Move(stack<T>& s, stack<T>& d)
	{
		size_t size = s.size();
		while (size--)
		{
			d.push(s.top());
			s.pop();
		}
	}
private:
	stack<T> s1;
	stack<T> s2;
};





void Test()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << q.Size() << endl;
	q.Pop();
	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;
}




