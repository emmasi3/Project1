#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int money = 0;
	printf("所收取总金额：\n");
	scanf("%d", &money);

	int price = 0;
	printf("应收客户金额：\n");
	scanf("%d", &price);

	int a = money >= price;
	printf("a=%d\n", a);
	//计算金额
	if (a==1) {/////////////////////!!!!!看清楚了，==不等于=。如果你这里写的是a=1,那么程序将不会执行else语句，
		printf("应找客户金额：%d\n", money - price);
	}
	else {
		printf("您的钱不够\n");
	}
	return 0;
}
/*1. 这里所说的执行体，也就是判断条件==判断语句，必须用    ==     绝对不能用 =  来当等于号，不然else语句不会执行*/