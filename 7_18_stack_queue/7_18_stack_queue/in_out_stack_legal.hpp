#pragma once


#include<stack>

//入栈序列 s
//出栈序列 d
//1.s与d的长度不相等，false
//2.s的第一个元素进栈，判断栈顶元素和出栈序列指针指向的元素是否相等
	//2.1 相等，出栈操作，d指针向后移
	//2.2 不相等 ，如果s不为空，继续入栈，直到匹配
	//2.3 如果s=="\0";false
//

bool Is_in_out_stack_legal(char* s, char* d)
{
	stack<char> sk;

	if (strlen(s) != strlen(d))
		return false;

	sk.push(*s++);

	while (*d != '\0')
	{
		while (sk.top() != *d && *s != '\0') 
			sk.push(*s++);

		if (sk.top() == *d++)
		{
			sk.pop();
			continue;
		}
		if (*s == '\0'&& sk.top() != *d)
			return false;
	}
	return true;
 }


void In_Out_Stack()
{
	char* s = "12345";
	char* d = "67890";
	if (Is_in_out_stack_legal(s, d))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

}






