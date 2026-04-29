#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>
void f1(const int x);
void f2(const int a[]);

int main()
{
	int x = 6;
	f1(x);

	int a[] = { 1,2,3,4,5,6, };
	f2(a);

	return 0;
}

void f1(const int x) {
	printf("%d\n", x);
	// 1. const 与变量，在函数中，有时候输入进去变量，但是会由于某些原因被修改，所以为了避免数据被修改，只需要
	//  . 定义函数输入值，为 const 即可
}

void f2(const int a[]) {
	// 2. const 与数组，同上，一旦规定了输入的东西为 const 所修饰，那么数组中的任何数据都不能修改！！
}