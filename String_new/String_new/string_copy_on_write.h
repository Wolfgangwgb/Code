#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String_copy
{
public:
	String_copy(const char* str = "")
		:_str(new char[strlen(str) + 4 + 1])
	{
		if (*str == 0)
		{
			*((int*)_str) = 1;
			_str += 4;
			*_str = '\0';
		}
		else
		{
			*((int*)_str) = 1;
			_str += 4;
			strcpy(_str, str);
		}

	}

	String_copy(const String_copy& s)
	{
		_str = s._str;
		++(*(int*)(_str - 4));
	}

	String_copy& operator=(const String_copy& s)
	{
		if (this != &s)
		{
			if (--(*((int*)(_str - 4))) == 0)
			{
				delete[](_str - 4);
				_str = 0;
			}
			_str = s._str;
			++(*((int*)(_str - 4)));
		}
		return *this;
	}

	~String_copy()
	{
		if (_str)
		{
			if (--(*((int*)(_str - 4))) == 0)
			{
				delete[](_str - 4);
				_str = 0;
			}
		}
	}

private:
	char* _str;
};

void Test_copy()
{
	String_copy s1("hello wgb");
	String_copy s2(s1);
	String_copy s3 = s2;
	String_copy s4;
	s4 = s3;
}