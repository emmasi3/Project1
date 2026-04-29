#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>
void comp(int a[],int *min,int *max);

int main()
{
	int a[] = { 1,8,5,6,18,59,45,65,35,25,79,82,28 };
	int min, max;
	//
	int len = sizeof(a) / sizeof(a[0]);
	printf("%d\n", len);
	//
	comp(a, &min, &max);
	//
	printf("min=%d\tmax=%d\n", min, max);

	return 0;
}
void comp(int a[], int* min, int* max) {
	// 1. “数组传参”实际上传输的是--a[]首个地址的指针，也就是 comp(a,&min,&max);--a是一个指针，只不过 没“*”而已
	// 
	//  . 那么传进来的也只能是 a 指向 变量（a[0]）的“地址”,也就是-- “a=&a[0]”;!!
	*min = a[0];
	*max = a[0];
	//
	int i;
	printf("%d\n", sizeof(a));
	int len = sizeof(a) / sizeof(a[0]);
	printf("%d\n", len);
	for (i = 1; i < (sizeof(a) / sizeof(a[0])); i++) {
		if (*min > a[i]) {
			*min = a[i];
		}
		if (*max < a[i]) {
			*max = a[i];
		}
	}
}