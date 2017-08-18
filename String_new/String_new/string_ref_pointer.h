#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String_pointer_int
{
public:
	String_pointer_int(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _count(new int(0))
	{
		if (*str == 0)
			*_str = '\0';
		else
			strcpy(_str, str);
		*_count = 1;
	}

	String_pointer_int(const String_pointer_int& s)
	{
		_str = s._str;
		++(*s._count);
		_count = s._count;
	}

	String_pointer_int& operator=(const String_pointer_int& s)
	{
		if (this != &s)
		{
			if (_str)
				delete[] _str;
			_str = s._str;
			++(*s._count);
			_count = s._count;
		}
		return *this;
	}

	~String_pointer_int()
	{
		if (_str)
		{
			if (--(*_count) == 0)
			{
				delete[] _str;
				delete _count;
				_count = 0;
				_str = 0;
			}
		}
	}

private:
	int* _count;
	char* _str;
};

void Test_pointer_count()
{
	String_pointer_int s1("hello wgb");
	String_pointer_int s2(s1);
	String_pointer_int s3 = s2;
	String_pointer_int s4;
	s4 = s3;
}

//空间释放成功
//用指针的缺点：1.空间浪费   2.可能忽略释放
