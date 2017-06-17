#include<stdio.h>
#include<Windows.h>



int my_strcmp(const char* str1,const char* str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}

	if((*str1 - *str2) > 0)
		return 1;
	else
		return -1;
}


int main()
{
	char arr[] = "abcdef";
	int ret = 0;
	ret = my_strcmp(arr,"abcdefgh");
	printf("%d\n",ret);
	system("pause");
	return 0;
}