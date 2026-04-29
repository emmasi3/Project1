#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>
void swap(int* pa, int* pb);

int main()
{
	int pa = 5;
	int pb = 6;
	//
	swap(&pa, &pb);// 1. 利用这个指针的特性，可以在外部函数内对其他“块”内的变量交换值，这在“指针”以前好西藏是办不到的
	//
	printf("pa=5-->pa=%d\n", pa);

	printf("pb=6-->pb=%d\n", pb);

	return 0;
}
void swap(int* pa, int* pb) {
	int t = *pb;
	*pb = *pa;
	*pa = t;
}