#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<string>
//Éî¿½±´

class String_s
{
public:
	String_s(const char* str = "")
		:_str(new char[strlen(str)+1])
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

	String_s(const String_s& ss)
		:_str(new char[strlen(ss._str)+1])
	{
		strcpy(_str,ss._str);
	}

	String_s& operator=(const String_s& ss)
	{
		if (this != &ss)
		{
			char* tmp = new char[strlen(ss._str)+1];
			strcpy(tmp,ss._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;
	}

	~String_s()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

void Test_s()
{
	String_s s1("hello wgb");
	String_s s2(s1);
	String_s s3 = s2;
	String_s s4;
	s4 = s3;
}