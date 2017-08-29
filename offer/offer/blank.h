#pragma once
#include<iostream>
using namespace std;

/*char* replaceSpace(char *str, int length) {
int count = 0;
for (int i = 0; i<length; i++){
if (isspace(str[i]))
count++;
}
int new_length = count * 3 + length-2;
char* p = (char*)malloc(new_length);
if (p != NULL){
memset(p, 0, new_length);
strncpy(p, str, length);
for (int i = length; i>0; i--){
if (isspace(p[i])){
p[new_length] = '0';
p[new_length - 1] = '2';
p[new_length - 2] = '%';
new_length -= 3;
}
else{
p[new_length] = p[i];
new_length--;
}
}
}
return p;
}*/

void replaceSpace(char *str, int length)
{
	if (str == NULL)
		return;
	int countblank = 0;
	int orignlength = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		orignlength++;
		if (str[i] == ' ')
			countblank++;
	}
	int new_len = orignlength + 2 * countblank;
	if (new_len + 1 > length)
		return;
	char* pstr1 = str + orignlength;
	char* pstr2 = str + new_len;
	while (pstr1 < pstr2)
	{
		if (isspace(*pstr1))
		{
			*pstr2-- = '0';
			*pstr2-- = '2';
			*pstr2-- = '%';
		}
		else
		{
			*pstr2-- = *pstr1;
		}
		--pstr1;
	}
}

void Test_blank()
{
	char str[18] = "we are happy.";
	replaceSpace(str,sizeof(str)/sizeof(str[0]));
}