#pragma once

#include<iostream>
#include<vector>
#include<list>
using namespace std;

//
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
{
	list<int> l;
	vector<int> tmp;
	for (int i = 0; i < input.size(); i++)
	{
		l.push_back(input[i]);
	}
	l.sort();	
	for (int i = 0; i < k; i++)
	{
		tmp.push_back(l.front());
		l.pop_front();
	}
	return tmp;
}

template <class T>
struct Less
{
	bool operator()(T& left, T& right)
	{
		return left < right;
	}
};
template <class T>
struct Greater
{
	bool operator()(T& left, T& right)
	{
		return left > right;
	}
};


template <class T, class Compare = Less<T>>
class Heap
{
public:
	Heap()
	{}
	Heap(const vector<T> arr, size_t size)
	{
		_v.resize(size);//申请空间
		for (size_t i = 0; i < size; ++i)
		{
			_v[i] = arr[i];
		}
		//找到倒数第一个非叶子结点---vector最后一个元素的双亲
		int root = (_v.size() - 2) >> 1;
		for (; root >= 0; --root)
		{
			Adjust(root);
		}
	}

	void Push_heap(const T& value)
	{
		_v.push_back(value);
		if (_v.size() == 1)
			return;
		int root = _v.size() - 1;
		Adjust(root);
	}

	size_t Size()
	{
		return _v.size();
	}

	bool Empty()
	{
		return _v.empty();
	}

	T& Top()
	{
		return _v[0];
	}

	void pop_heap()
	{
		if (!_v.empty())
		{
			std::swap(_v[0], _v[_v.size() - 1]);
			_v.pop_back();
			Adjust(0);
		}
	}
private:
	void Adjust(size_t root)
	{
		Compare com;
		size_t parent = root;
		size_t child = 2 * root + 1;//左孩子
		while (child<_v.size())
		{
			if (child + 1 < _v.size() && com(_v[child + 1], _v[child])/* _v[child + 1] < _v[child]*/)//左右孩子最小的一个
				child += 1;
			if (com(_v[child], _v[parent]))//判断孩子跟双亲的大小
			{
				std::swap(_v[child], _v[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				return;
			}
		}
	}

private:
	vector<T> _v;
};
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> v;
	if (k > input.size || input.empty())
		return v;
	Heap<int> h(input,input.size());
	
	for (int i = 0; i < k; i++)
	{
		v.push_back(h.Top());
		h.pop_heap();
	}
	return v;
}

void Test_min_k()
{
	//4, 5, 1, 6, 2, 7, 3, 8
	vector<int> ret;
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(6);
	v.push_back(2);
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);
	ret = GetLeastNumbers_Solution(v,4);
}


