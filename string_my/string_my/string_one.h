#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<string>
//Éî¿½±´

class String_s
{
public:
	String_s(const char* str = "")
		:_size(strlen(str)+1)
	{
		_str = new char[_size];
		strcpy(_str,str);
		_str[_size] = '\0';
	}

	String_s(const String_s& ss)
		:_size(ss._size)
	{
		if (this != &ss)
		{
			if (_str)
				delete[] _str;
			_str = new char[_size];
			strcpy(_str,ss._str);
			_str[_size] = '\0';
		}
	}

	~String_s()
	{
		if (_str)
		{
			delete[] _str;
			_size = 0;
		}
	}
private:
	char* _str;
	int _size;
};

void Test1()
{
	String_s ss("hello wgb");
	String_s sss(ss);
}