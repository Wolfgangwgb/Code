#include<stdio.h>
#include<windows.h>
#include <assert.h>

//void *memcpy( void *dest, const void *src, size_t count );



void* my_memcpy(void* dest, const void* src,int num)
{
	char* pdest = dest;
	char* psrc = src;

	assert(dest);
	assert(src);

	while(num)
	{
		*pdest++ = *psrc++;
		num--;
	}

	return dest;
}


int main()
{
	char s1[] = "            ";
	char s2[] = "************************************";
	my_memcpy(s2+12,s1,6);
	printf("%s\n",s2);
	system("pause");
	return 0;
}