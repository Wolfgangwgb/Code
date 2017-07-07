#include<stdio.h>
#include<Windows.h>
#include<string.h>

//冒泡排序
//
//冒泡排序是非常容易理解和实现，，以从小到大排序举例：
//设数组长度为N。
//1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
//2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
//3．N=N-1，如果N不为0就重复前面二步，否则排序完成



//void swap(int *num1,int *num2)
//{
//	int tmp = *num1;
//	*num1 = *num2;
//	*num2 = tmp;
//}
////
////
////int main()
////{
////	int a= 2;
////	int b = 3;
////	swap(&a,&b);
////	printf("%d %d\n",a,b);
////	system("pause");
////	return 0;
////}
//void bubble_sort(int arr[],int sz)
//{
//	int i,j;
//	for(i=0; i<sz-1; i++)
//		for(j=0; j<sz-1-i; j++)
//			if(arr[j] <arr[j+1])
//				swap(&arr[j],&arr[j+1]);
//	//		{
//	//			int tmp = arr[j];
//	//			arr[j] = arr[j+1];
//	//			arr[j+1] = tmp;
//	//			flag = 1;
//	//		}
//	//	}
//
//	//}
//
//}
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,0};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	system("pause");
//	return 0;
//}












//自己实现一个bubble_sort(冒泡排序)，可以完成不同类型数据的排序。

typedef struct Stu
{
	char name[20];
	int age;
}Stu,*pstu;


void swap(void *elem1, void *elem2, int width)
{
	int i = 0;
	for(i=0; i<width; i++)
	{
		char tmp = *((char*)elem1+i);
		*((char*)elem1+i) =  *((char*)elem2+i);
	    *((char*)elem2+i) = tmp;
	}
}


//int compare(const void *elem1, const void *elem2)
//{
//     return *((int*)elem1) - *((int*)elem2);
//}
//int compare(const void *elem1, const void *elem2)
//{
//	return *((char*)elem1) - *((char*)elem2);
//}

int compare(const void *elem1, const void *elem2)
{
	return strcmp(((pstu)elem1)->name,((pstu)elem2)->name);
	/*return (((pstu)elem1)->age - ((pstu)elem2)->age);*/
}



void bubble_sort(void *base, int sz, int width, int (*compare )(const void *elem1, const void *elem2 ))
{
	int i,j;
	for(i=0; i<sz-1; i++)
	{
		for(j=0; j<sz-1-i; j++)
		{
			if((compare((char*)base+j*width,(char*)base+(j+1)*width))>0)
				swap((char*)base+j*width,(char*)base+(j+1)*width,width);
		}
	}
}
void test1()
{

	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]),compare);
	for(i=0; i<sz; i++)
	{
		printf("%d ",arr[i]);
	}
}

void test2()
{
	char arr[] = {'b','a','d','c','\0'};
	int sz = strlen(arr);
	bubble_sort(arr,sz,sizeof(char),compare);
	printf("%s ",arr);
}
void test3()
{
	Stu stu[3]= {{"yby",3},{"wgb",32},{"zpw",2}};
	int sz = sizeof(stu)/sizeof(stu[0]);
	int i = 0;
	bubble_sort(stu,sz,sizeof(stu[0]),compare);
	//qsort(stu,sz,sizeof(stu[0]),compare);
	for(i=0; i<sz; i++)
	{
		printf("name = %s age = %d \n",stu[i].name,stu[i].age);
	}
}
int main()
{	
    //test1();
	//test2();
	test3();
	system("pause");
	return 0;
}