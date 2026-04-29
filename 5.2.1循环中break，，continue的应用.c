#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	printf("请输入：\n");
	scanf("%d", &x);

	int i = 0;
	int n = x;
	int a;
	int N=0;

	for (i = 2; i < n; i++) {
		a = n % i;
		if (a == 0) {
			N++;
			printf("%d不是素数\n", x);
			break;                 //如果在循环中遇到break，那么break下面的 循环中的代码将 不再执行，退出“ 整个 循环”！
		}
	}
	if (N == 0) {
		printf("%d是素数\n", x);  //相反，如果有continue在，以下（循环内）的代码 “也”不再执行，直接返回循环第一行
		                          //继续执行直到循环条件达到终止要求！！

	}

	return 0;
}