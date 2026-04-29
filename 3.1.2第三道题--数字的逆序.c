#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;

	printf("请输入三位数整数：\n");
	scanf("%d%d%d", &a, &b, &c);

	int d = a * 100 + b * 10 + c;
	int e = c*100+b*10+a;

	printf("则 %d 的逆序为 %d ",d,e);

	return 0;
}