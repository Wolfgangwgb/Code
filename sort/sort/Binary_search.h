#pragma once


//区间：左闭右开
int Binary_search(int arr[], int key,int size)
{
	int left = 0;
	int right = size;//区间不同，变
	int mid = 0;
	while (left < right)//区间不同，变
	{
		mid = (left + right)>>1;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid]<key)
		{
			left = mid+1;
		}
		else
		{
			right = mid;//区间不同，变
		}
	}
	return -1;
}

//区间：左闭右闭
int Binary_search1(int arr[], int key, int size)
{
	int left = 0;
	int right = size-1;//区间不同，变
	int mid = 0;
	while (left <= right)//区间不同，变
	{
		mid = (left + right) >> 1;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid]<key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;//区间不同，变
		}
	}
	return -1;
}
void Test_Binary()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	Binary_search(arr,2,sizeof(arr)/sizeof(arr[0]));
}