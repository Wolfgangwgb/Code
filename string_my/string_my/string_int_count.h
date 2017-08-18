#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String_intcount
{
public:
	String_intcount(const char* str = "")
		:_str(new char[strlen(str) + 1])
		, _count(0)
	{
		if (*str == 0)
			*_str = '\0';
		else
			strcpy(_str, str);
		++_count;
	}

	String_intcount(String_intcount& s)
	{
		_str = s._str;
		++(s._count);
		_count = s._count;
	}

	String_intcount& operator=( String_intcount& s)
	{
		if (this != &s)
		{
			if (_str)
				delete[] _str;
			_str = s._str;
			++(s._count);
			_count = s._count;
		}
		return *this;
	}

	~String_intcount()
	{
		if (_str)
		{
			if (--_count == 0)
			{
				delete[] _str;
				_str = 0;
			}
		}
	}

private:
	int _count;
	char* _str;
};


void Test_int_count()
{
	String_intcount s1("hello wgb");
	String_intcount s2(s1);
	String_intcount s3 = s2;
	String_intcount s4;
	s4 = s3;
}
//计数器不统一，最后释放计数器没有一个等于0，所以没有释放