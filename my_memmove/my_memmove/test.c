#include<stdio.h>
#include<windows.h>
#include<assert.h>

void* my_memmove(void* dest, const void* src, int num)
{
    char* pdest = dest;
    char* psrc = src;
    
	assert(dest);
	assert(src);

	if((pdest >= psrc) && (pdest <= psrc+num))
	{
		while(num)
		{                                           
			*(pdest+num-1) = *(psrc+num-1);                    //从后向前
			num--;
		}
	}
	else
	{
		while(num)
		{
			*pdest++ = *psrc++;                           //从前向后
			num--;                      
		}
	}
	return dest;
}


int main()
{
	char arr[] = {1,2,3,4,5,6,7,8,9,0};
    int i = 0;
	my_memmove(arr,arr+1,5);
	for(i=0; i<10; i++)
	{
		printf("%d ",arr[i]);
	}

	//char p1[256] = "hello world!" ;
	//char p2[256] = { 0 };
	//my_memmove(p1+2, p1, 4);
	//printf( "%s\n", p1);
	//my_memmove( NULL, p1, strlen(p1) + 1);
	//my_memmove(p2, NULL, strlen(p1) + 1);
	//my_memmove(p1 + 1, p1, strlen(p1) + 1);
	//printf( "%s\n", p1);
	//my_memmove(p1, p1 + 1, strlen(p1) + 1);
	//printf( "%s\n", p1);
	system("pause");
	return 0;
}




//void* my_memmove(void* dest, const void* src, int num)
//{
//	void* ret =dest;
//
//	assert(dest);
//	assert(src);
//
//	if((dest >= src) && (dest <= src+num))
//	{
//		while(num)
//		{                                           //从后向前
//			*(( char *)dest+num-1) = *(( char *)src+num-1);
//			num--;
//		}
//	}
//	else
//	{
//		while(num)
//		{
//			*dest = *( char *)src;
//			dest+=1;
//			src+=1;
//			num--;                      //从前向后
//		}
//
//	}
//	return ret;
//}
////
////void * MyMemMove(void *dst,  void *src, int count )
////{
////	void * ret = dst ;
////
////	assert(dst );
////	assert(src );
////	
////	if (dst <= src || ( char *)dst >= ((char *) src + count )) {
////		while (count --) {
////			*( char *)dst = *(char *) src;
////			dst = (char *)dst + 1;
////			src = (char *)src + 1;
////		}
////	}
////	else {
////		dst = (char *)dst + count - 1;
////		src = (char *)src + count - 1;
////		//逆序拷贝
////		while (count --) {
////			*(char *)dst = *(char *) src;
////			dst = (char *)dst - 1;
////			src = (char *)src - 1;
////		}
////	}
////	return(ret);
////}

