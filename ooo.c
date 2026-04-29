#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
int main()
{
	int *array;
	int n;
	scanf("%d", &n);
	array = (int *)malloc(n * sizeof(int));  //malloc()函数返回值为：（void*）【类型，这不算类型】，(int *)作用-转换为
	//（int*） 类型的指针（malloc的返回值）
	
	return 0;
}