#pragma once
#include<string>

void Arr_sort(int arr[], int n)
{
	//ÕÒ×î´óÖµ
	int maxvalue = 0;
	int minvalue = 0;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (arr[i]>maxvalue)
			maxvalue = arr[i];
		if (arr[i]<minvalue)
			minvalue = arr[i];
	}
	int range = maxvalue - minvalue + 1;
	int *tmp = new int[range];
	memset(tmp, 0, sizeof(int)*(range));
	for (i = 0; i < n; ++i)
	{
		tmp[arr[i] - minvalue]++;
	}
	int j = 0;
	for (i = 0; i < range; ++i)
	{
		while (tmp[i]--)
		{
			arr[j] = minvalue + i;
			j++;
		}
	}
	delete[]tmp;
}


void Test_arr()
{
	int a[] = { 12, 13, 12, 13, 19, 18, 15, 12, 15, 16, 17 };
	Arr_sort(a, sizeof(a) / sizeof(a[0]));
}
