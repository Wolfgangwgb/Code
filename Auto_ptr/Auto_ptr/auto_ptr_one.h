#pragma once
#include<iostream>
using namespace std;

//auto_ptr版本的智能指针采用的是管理权转移的方法，
//即由a构造出b对象之后，a对象置为NULL，即之后不能
//再访问a对象，只有b一个对象维护该空间。

//缺点：不能真正实现拷贝构造和赋值运算符重载的目的
template <class T>
class Auto_ptr
{
public:
	Auto_ptr()
		:_ptr(NULL)
	{}

	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{}
	//拷贝构造--管理权转移
	Auto_ptr(Auto_ptr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;//失效
	}
	//赋值运算符重载--管理权转移
	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
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

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};

struct TT
{
	int a = 1;
	char c = 'x';
};
///////////////////////////////////////////////////
//////////////////////////////////////////////////
//产生的问题
// 问题一: 资源转移后，ap1,ap2再不能访问空间了
//问题二：const类型的指针，再不能由它拷贝别的指针了
//问题三：当智能指针做函数实参传递时，则该智能指针在函数中再不能访问
void Test()
{
	int* p = new int;
	Auto_ptr<int> ap(p);
	Auto_ptr<int> ap1(ap);
	Auto_ptr<int> ap2(new int);
	ap2 = ap1;
	//*ap = 10;//失效，无法访问
	//*ap1 = 20;
	//const Auto_ptr<int> app(p);
	//Auto_ptr<int> app1(app);


	/*Auto_ptr<TT> ap2 = new TT;
	ap2->a = 22;
	cout << ap2->a << endl;
	cout << ap2->c << endl;*/

}