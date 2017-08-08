#include<iostream>
using namespace std;
#include<string>
#include"bitmap.h"
#include"bloom_filter.h"



void Test()
{
	Bitmap b(2048);
	size_t arr[] = { 31, 32, 6, 34, 76, 954, 23, 42, 57, 12 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		b.Set(arr[i]);
	}
	if (b.Exist(34))
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	b.Reset(34);
	if (b.Exist(34))
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	if (b.Exist(0))
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}

//void Ring_right_shift(char p[], int k,int n)
//{
//	if (0 == k || n == 0)
//		return;
//	while (k--)
//	{
//		char ret = p[n-1];
//		for (int i = n - 1; i >= 0; --i)
//		{
//			p[i+1] = p[i];
//		}
//		p[0] = ret;
//	}
//}
void Test_Bloom()
{
	string str("hello");
	string str1("ello");
	Bloom_Filter<string> bf(1024);
	bf.Set(str);
	if (bf.Exist_bloom(str))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (bf.Exist_bloom(str1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
int main()
{
 	//char p[] = { 'a', 'b', 'c', 'd', 'e','f','g','h','i'};
	//Ring_right_shift(p,3,sizeof(p)/sizeof(p[0]));
	//Ring_right_shift(p, 6, sizeof(p) / sizeof(p[0]));
	//Test();
	Test_Bloom();
	return 0;
}