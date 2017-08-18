#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<string>
//Éî¿½±´

class String_s_third
{
public:
	String_s_third(const char* str = "")
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

	String_s_third(const String_s_third& ss)
		:_str(NULL)
	{
		String_s_third tmp(ss._str);
		std::swap(_str, tmp._str);
	}

	String_s_third& operator=(const String_s_third& ss)
	{
		if (this != &ss)
		{
			String_s_third tmp(ss._str);
			std::swap(_str, tmp._str);
		}
		return *this;
	}

	~String_s_third()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

void Test_d3()
{
	String_s_third s1("hello wgb");
	String_s_third s2(s1);
	String_s_third s3 = s2;
	String_s_third s4;
	s4 = s3;
}