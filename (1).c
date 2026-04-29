#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int money = 0;
	printf("所收取总金额：");

	scanf("%d", &money);
	int price = 0;
	printf("应收客户金额：");
	scanf("%d", &price);

	int sum = 0;
	sum = money - price;
	printf("应找回客户：%d", sum);

	return 0;
}