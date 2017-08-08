#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>

//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
int atoi_my(const char* str)
{
	bool falg = false;
	while (isspace(*str) > 0)//跳过空格
		++str;

	if (*str == '-' || *str == '+')//正负号
	{
		if (*str == '-')
			falg = true;
		str++;
	}
	// while(*str>='0'&&*str<='9')  //不用管非数字字符
	if (isdigit(str[0]) == 0)//第一个是非数字字符
		return 0;
	else
	{
		int ret = 0;
		while (isdigit(*str) > 0)
		{
			ret = ret * 10 + (*str - '0');
			str++;
			if (ret < 0)
			{
				ret = 2147483647;
				break;
			}
		}
		return ret*(falg?-1:1);
	}
}

void Test()
{
	cout << atoi_my("122345677876544323214556667577") << endl;
	cout << atoi_my("-123") << endl;
	cout << atoi_my("+123") << endl;
	cout << atoi_my("") << endl;
	cout << atoi_my("123") << endl;
	cout << atoi_my("   123") << endl;
	cout << atoi_my("   a123") << endl;
	cout << atoi_my("123.123") << endl;
	cout << atoi_my("a123") << endl;
	cout << atoi_my("12ddd3") << endl;
	cout << atoi_my("123ddd") << endl;
	cout << atoi_my("abcd") << endl;
}			

void Test_atoi()
{
	cout << atoi("") << endl;
	cout << atoi("123") << endl;
	cout << atoi("   123") << endl;
	cout << atoi("123.123") << endl;
	cout << atoi("a123") << endl;
	cout << atoi("12ddd3") << endl;
	cout << atoi("123ddd") << endl;
	cout << atoi("abcd") << endl;
	cout << atoi("122345677876544323214556667577") << endl;
	cout << atoi("-122121212") << endl;
	cout << atoi("+122121212") << endl;
}

//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
char* reverse(char* str)
{
	//"1234"
	char* head = str;//字符串头
	char* tail = str;//字符串尾
	while (*tail != '\0')
		++tail;
	--tail;
	char tmp;
	while (head<tail)
	{
		tmp = *head;
		*head++ = *tail;
		*tail-- = tmp;
	}
	return str;
}
char* itoa_my(int val)
{
	int tmp = val;
	if (tmp < 0)
		tmp = -tmp;
	static char str[100];//??
	int i = 0;
	while (tmp>0)
	{
		str[i++] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (val < 0)
		str[i++] = '-';
	str[i] = '\0';
	return reverse(str);
}

void Test_itoa()
{
	cout<<itoa_my(1234)<<endl;
	cout<<itoa_my(-1234)<<endl;
}



//////////////////////////////////////////////////////
/////////////////////////////////////////////////////



/*
int main()
{

	//Test();
	//Test_itoa();
	
	return 0;
}*/