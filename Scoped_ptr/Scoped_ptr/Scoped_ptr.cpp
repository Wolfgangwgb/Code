#pragma once

using namespace std;


//scoped_ptr 防拷贝
//不用拷贝构造函数和赋值运算符重载

template <class T>
class Scoped_ptr
{
public:
	Scoped_ptr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	~Scoped_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	Scoped_ptr(const Scoped_ptr<T>& sp);
	Scoped_ptr<T>& operator=(const Scoped_ptr<T>& sp);
protected:
	T* _ptr;
};

int main()
{
	Scoped_ptr<int> ap(new int);
	Scoped_ptr<int> ap1(new int);
	//ap = ap1;
	//Scoped_ptr<int> ap2(ap);
	return 0;
}

/*
//方法一：将拷贝构造函数和赋值运算符重载函数给成私有成员函数，给出函数定义，函数体可以为NULL，因为没有任何意义
private:
//给出定义
scopedptr(const scopedptr<int>& sp)
{}
scopedptr<T> operator=(const scopedptr<T>& ap)//缺点：不清楚如何给出实体
{}

//方法二：将拷贝构造函数和赋值运算符重载函数给成公共的类成员函数，但不给出定义
scopedptr(const scopedptr<int>& sp);
scopedptr<T> operator=(const scopedptr<T>& ap);//缺点：这种情况可能会有用户在类的外面自己定义

//方法三：将拷贝构造函数和赋值运算符重载函数给成私有的成员函数，但只声明不定义
private:
scopedptr(const scopedptr<int>& sp);
scopedptr<T> operator=(const scopedptr<T>& ap);//防拷贝的最好的选择

//方法四：不给出拷贝构造函数和赋值运算符重载函数

//缺点：编译器会自动合成
*/