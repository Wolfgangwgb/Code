#pragma once


//÷±Ω”≤Â»Î≈≈–Ú


void Insert_sort(int arr[], int n)
{
	int idx1=0;
	int temp=0;
	int idx2 = 0;
	for (idx1 = 1; idx1 < n; ++idx1)
	{
		temp = arr[idx1];
		idx2 = idx1 - 1;
		while (idx2>=0&&arr[idx2]>temp)
		{
			arr[idx2 + 1] = arr[idx2];
			--idx2;
		}
		arr[idx2 + 1] = temp;
	}
}

void Test1()
{
	int a[] = {9,5,3,6,4,8,6};
	Insert_sort(a,sizeof(a)/sizeof(a[0]));
}

//’€∞Î≤Â»Î≈≈–Ú(∂˛∑÷≤È’“)
void Insert_sort_binary(int arr[], int n)
{
	int idx1 = 0,temp = 0,idx2 = 0;
	int mid = 0, left = 0, right = 0;

	for (idx1 = 1; idx1 < n; ++idx1)
	{
		temp = arr[idx1];
		left = 0;
		right = idx1 - 1;

		while (left<=right)
		{
			mid = (left + right) >> 1;
			if (arr[mid] < temp)
				left = mid + 1;
			else
				right = mid - 1;
		}
		for (idx2 = idx1 - 1; idx2 >= right + 1; --idx2)
			arr[idx2 + 1] = arr[idx2];
		arr[right + 1] = temp;
	}
}

void Test2()
{
	int a[] = { 9, 5, 3, 6, 4, 8, 6 };
	Insert_sort_binary(a,sizeof(a)/sizeof(a[0]));
}


//œ£∂˚≈≈–Ú


void Shell_sort(int arr[], int n)
{
	int idx1, idx2, d, temp;
	d = n / 2;
	while (d > 0)
	{
		for (idx1 = d; idx1 < n; ++idx1)
		{
			temp = arr[idx1];
			idx2 = idx1 - d;
			while (idx2 >= 0 && arr[idx2]>temp)
			{
				arr[idx2 + d] = arr[idx2];
				idx2-=d;
			}
			arr[idx2 + d] = temp;
		}
		d /= 2;
	}
}

void Test3()
{
	int a[] = { 9, 5, 3, 6, 4, 8, 6 };
	Shell_sort(a,sizeof(a)/sizeof(a[0]));
}