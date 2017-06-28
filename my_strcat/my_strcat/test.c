#include <stdio.h>
#include <Windows.h>
#include <assert.h>


char* my_strcat(char* dest,const char* src)
{
    char *ret = dest;

	assert(dest);
	assert(src);
	
	while(*dest)
		dest++;        //找到目标串\0的位置

	while(*dest++ = *src++)
		;                 //从目标串\0的位置开始把src放进去

	return ret;
}

int main()
{
	char arr[20] = "qqqqqq";    //数组的大小必须足够
	my_strcat(arr,"abcdef");
	printf("%s\n",arr);
	system("pause");
	return 0;
}