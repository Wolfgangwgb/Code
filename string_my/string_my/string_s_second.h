#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<string>
//Éî¿½±´

class String_s_second
{
public:
	String_s_second(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		if (*str == 0)
		{
			*_str = '\0';
		}
		else
		{
			strcpy(_str, str);
		}
	}

	String_s_second(const String_s_second& ss)
		:_str(new char[strlen(ss._str) + 1])
	{
		strcpy(_str, ss._str);
	}

	String_s_second& operator=(const String_s_second& ss)
	{
		if (this != &ss)
		{
			delete[] _str;
			_str = new char[strlen(ss._str) + 1];
			strcpy(_str, ss._str);
		}
		return *this;
	}

	~String_s_second()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

void Test_s_second()
{
	String_s_second s1("hello wgb");
	String_s_second s2(s1);
	String_s_second s3 = s2;
	String_s_second s4;
	s4 = s3;
}