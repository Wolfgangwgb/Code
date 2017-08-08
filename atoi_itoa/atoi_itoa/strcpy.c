#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>



char* strcpy_my(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while ((*dest++ = *src++)!='\0')
		;
	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	++dest;
	//	++src;
	//}
	//*dest = *src;
	return ret;
}

void Test_strcpy()
{
	char s[10] = "wgb";

	char* cc = strcpy_my(s, s + 1);
	size_t i = strlen(cc);
	char* ret = strcpy(s + 2, s);
}


///////////////////////////////////
//memcpy
void* memcpy_my(void* dest, const void*src, size_t count)
{
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	while (count--)
		*pdest++ = *psrc++;
	return dest;
}

////////////////////////////////////////////
//memmove
void* memmove_my(void* dest, const void*src, size_t count)
{
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;

	if (pdest >= psrc &&pdest <= psrc + count - 1)//从后向前
	{
		pdest = pdest + count - 1;
		psrc = psrc + count - 1;
		while (count--)
			*pdest-- = *psrc--;
	}
	else//从前向后
	{
		while (count--)
			*pdest++ = *psrc++;
	}
	return dest;
}
int main()
{
	char s[10] = "hello";
	char d[100] = "";
	//memcpy_my(s+1,s,5);
	//memcpy(s+1,s,5);
	memmove(s+1,s,5);
	return 0;
}