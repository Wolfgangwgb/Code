#pragma once
#include<iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
	if (NULL == arr && 0 == size)
		return;
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j >i; --j)//j>i因为每次将最小的移到最前面，前面的已有序
		{
			if (arr[j - 1]>arr[j])
				std::swap(arr[j-1],arr[j]);
		}
	}
}
//9,3,5,2,7,4,2,1
//1,9,3,5,2,7,4,2---第一趟
//1,2,9,3,5,2,7,4---第二趟
//1,2,2,9,3,5,4,7---第三趟
//1,2,2,3,9,4,5,7---第四趟
//1,2,2,3,4,9,5,7---第五趟
//1,2,2,3,4,5,9,7---第六趟
//1,2,2,3,4,5,7,9---第七趟

void Test_Bubble()
{
	int arr[] = {9,3,5,2,7,4,2,1};
	BubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
}