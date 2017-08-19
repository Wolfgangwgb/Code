#pragma once
#include<iostream>

void Select_sort(int arr[], int size)
{
	if (NULL == arr && 0 == size)
		return;
	int minindex = 0;
	for (int i = 0; i < size; ++i)
	{
		minindex = i;//每趟假设arr[i]最小，从i+1开始找最小的
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		if (minindex != i)//一趟找完，如果最小值的索引不等于i，说明找到了更小的，交换
			std::swap(arr[i], arr[minindex]);
	}
}

void Test_select()
{
	int arr[] = {5,2,7,1,3,4,12};
	Select_sort(arr,sizeof(arr)/sizeof(arr[0]));
}