#include <stdio.h>
#include <Windows.h>
#include <assert.h>


char* my_strcpy(char *dest,const char *src)       //char* 链式访问    const修饰防止函数内部改变值而发生错误
{
	char* ret = dest;
	assert(dest != NULL);    //断言（不合理的值）
	assert(src!= NULL);
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
    *dest = *src;
	return ret;
}


//char* my_strcpy(char *dest,const char *src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while(*dest++ = *src++);
//	NULL;
//	return ret;
//}

int main()
{
	char arr[10];
	my_strcpy(arr,"hello");
	printf("%s\n",arr);
	system("pause");
	return 0;
}