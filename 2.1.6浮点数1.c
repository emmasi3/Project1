#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	double foot = 0;
	double inch = 0;

	printf("请输入尺寸：\n");
	scanf("%lf %lf", &foot, &inch);

	printf("实际尺寸为：%lf", (foot + inch / 12) * 0.3048);

	return 0;

}
//这是最为彻底的改法，当然还有比较简便的
