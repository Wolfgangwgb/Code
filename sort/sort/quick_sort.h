#pragma once
#include<iostream>
//冒泡+二分+递归
int Quick_first(int arr[], int left, int right)
{
	int key = arr[left];
	int key_index = left;//保存基准值下标，最后交换
	while (left < right)
	{
		while (left < right&&arr[right] >= key)//右边的先走，才能保证找到最小的元素
			--right;
		while (left < right&&arr[left] <= key)
			++left;
		std::swap(arr[left],arr[right]);
	}
	std::swap(arr[key_index],arr[left]);//将基准元素与指针相遇的元素交换
	return left;
}

void Quick_sort(int arr[], int left, int right)
{
	if (left >= right)//递归的出口
		return;
	int mid = Quick_first(arr,left,right);
	Quick_sort(arr,left,mid-1);
	Quick_sort(arr,mid+1,right);
}

void Test_Quick()
{
	int arr[] = {4,2,1,6,8,9,3};
	int len = (sizeof(arr) / sizeof(arr[0]));
	Quick_sort(arr, 0, len-1);
}