#include <stdio.h>
#include <Windows.h>


//int my_strlen(char *src)
//{
//	int count = 0;
//	while(*src++ !='\0')
//	{
//		/*src++;*/
//		count++;          //计数法
//	}
//	return count;
//}
//
//
//int my_strlen(char *str)
//{
//	if(*str == '\0')
//		return 0;
//	else
//		return 1+my_strlen(str+1);    //递归
//}
//
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	while(*str)
//	{
//		str++;
//	}
//	return str-start;     //指针-指针
//}


int main()
{
    char ch[] = "hello world";
	printf("%d\n",my_strlen(ch));
	system("pause");
	return 0;
}