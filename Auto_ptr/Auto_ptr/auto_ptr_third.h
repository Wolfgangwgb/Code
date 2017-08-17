#pragma once
#include<iostream>
using namespace std;

template <class T>
class Auto_ptrref
{
public:
	Auto_ptrref(T* ptr = NULL)
		:_ptr(ptr)
	{}
	T* _ptr;
};

template <class T>
class Auto_ptr_third
{
public:
	Auto_ptr_third()
		:_ptr(NULL)
	{}

	Auto_ptr_third(T* ptr)
		:_ptr(ptr)
	{}
	//拷贝构造--管理权转移
	Auto_ptr_third(Auto_ptr_third<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;//失效
	}
	//赋值运算符重载--管理权转移
	Auto_ptr_third<T>& operator=(Auto_ptr_third<T>& ap)
	{
		if (this != &ap)
		{
			if (NULL != _ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	//重载autoptrref()
	operator Auto_ptrref<T>()//将Auto_ptr<T>转化为Auto_ptrref<T>
	{
		Auto_ptrref<T> temp(_ptr);
		_ptr = NULL;
		return temp;
	}

	//再重载一个拷贝构造函数
	Auto_ptr_third(const Auto_ptrref<T>& apr)
		:_ptr(apr._ptr)
	{}


	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_ptr_third()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};


void Test3()
{
	Auto_ptr_third<int> ap(Auto_ptrref<int>(Auto_ptr_third<int>(new int)));
}