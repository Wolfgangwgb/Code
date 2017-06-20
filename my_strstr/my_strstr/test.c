#include<stdio.h>
#include<Windows.h>
#include<assert.h>


char* my_strstr(const char* str,const char* substr)
{
	char* cur = str;
    char* s1 = NULL;
	char* s2 = NULL;

	assert(str);
	assert(substr);

	while(*cur)
	{
		s1 = cur;
		s2 = substr;
		while((*s1 == *s2)&&(*s2))
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
			return cur;
		cur++;
	}
	return NULL;
}



int main()
{
     char* ret = my_strstr("abcedefghjk","jk");
	if(ret == NULL)
	{
		printf("no\n");
	}
	else
	{
		printf("yes\n");
	}
	
	system("pause");
	return 0;
}