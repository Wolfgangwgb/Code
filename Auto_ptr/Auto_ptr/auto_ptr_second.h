#pragma once
#include<iostream>
using namespace std;

//auto_ptr版本的智能指针采用的是管理权转移的方法，
//即由a构造出b对象之后，a对象置为NULL，即之后不能
//再访问a对象，只有b一个对象维护该空间。

//缺点：不能真正实现拷贝构造和赋值运算符重载的目的
template <class T>
class Auto_ptr_second
{
public:
	Auto_ptr_second()
		:_ptr(NULL)
		, _owner(false)
	{}

	Auto_ptr_second(T* ptr)
		:_ptr(ptr)
		, _owner(false)
	{
		if (NULL != ptr)
			_owner = true;
	}
	//拷贝构造--管理权转移
	Auto_ptr_second(const Auto_ptr_second<T>& ap)
		:_ptr(ap._ptr)
		, _owner(ap._owner)
	{
		ap._owner = false;
	}
	//赋值运算符重载--管理权转移
	Auto_ptr_second<T>& operator=(const Auto_ptr_second<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr && _owner)
			{
				delete _ptr;
				_ptr = ap._ptr;
			}
			_owner = true;
			ap._owner = false;
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

	~Auto_ptr_second()
	{
		if (_ptr)
		{
			if (_owner == true)
			{
				delete _ptr;
				_ptr = NULL;
				_owner = false;
			}
		}
	}
protected:
	T* _ptr;
	mutable bool _owner;
};
//mutable关键字，可变的，即使是const修饰的类对象，mutable修饰的类成员也是可以改变的


//虽然解决了问题一和问题二，但是产生了新的问题，ap1,ap2,ap4成为了野指针，只释放了ap5
void Test1()
{
	int* p = new int;
	Auto_ptr_second<int> ap(p);
	Auto_ptr_second<int> ap1(ap);
	Auto_ptr_second<int> ap2(new int);
	ap2 = ap1;
	*ap = 10;
	*ap1 = 20;

	const Auto_ptr_second<int> app(new int);
	Auto_ptr_second<int> app1(app);


}