#pragma once
#include<iostream>


//递归

//分组--合并
template <class T>
void Merge(T arr[], T start, T mid, T end, T n)
{
	T* tmp = new T[n];
	T i = start;
	T j = mid + 1;
	T k = 0;
	while (i<=mid&&j<=end)
	{
		if (arr[i]<=arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}
	if (i == mid+1)
	{
		while (j <= end)
			tmp[k++] = arr[j++];
	}
	else
	{
		while (i <= mid)
			tmp[k++] = arr[i++];
	}

	for (i = start, k = 0; i <= end; ++i, ++k)
		arr[i] = tmp[k];
	delete[] tmp;
}
template <class T>
void Merge_sort(T arr[], T start, T end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge_sort(arr,start,mid);
		Merge_sort(arr,mid+1,end);
		Merge(arr,start,mid,end,end-start+1);//??
	}
}
template <class T>
void Merge_sort_start(T arr[], T n)
{
	Merge_sort(arr,0,n-1);
}
void Test4()
{
	int arr[] = {4,1,6,5,8,12,89};
	Merge_sort_start<int>(arr,7);
}


