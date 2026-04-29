#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	printf("请输入：\n");
	scanf("%d", &n);
	//处理,次数
	int i;
	double sum = 0;

	//
	for (i = 1; i <= n; i++) {
		sum += 1.0 / i;
	}

	printf("数列{1/n}的前%d项和sum(%d)=%lf",n, n,sum);

	return 0;
}