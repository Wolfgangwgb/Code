#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		if (*str == 0)
			*_str = '\0';
		else
			strcpy(_str, str);
	}

	String(const String& s)
	{
		_str = s._str;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (_str)
				delete[] _str;
			_str = s._str;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = 0;
		}
	}

private:
	char* _str;
};

//当类里面有指针对象时，拷贝构造和赋值运算符重载只进行值拷贝(浅拷贝)，两个对象指向同一块内
//存，对象销毁时该空间被释放了两次，因此程序崩溃！
void Test_shallow_copy()
{
	String s1("hello wgb");
	String s2(s1);
	String s3 = s2;
	String s4;
	s4 = s3;
}