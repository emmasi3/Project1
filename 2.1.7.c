#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int hour1=0, minute1=0;
	int hour2=0, minute2=0;

	printf("请输入时间1：\n");
	scanf("%d时%d分", &hour1, &minute1);

	printf("请输入时间2：\n");
	scanf("%d时%d分", &hour2, &minute2);

	int t1 = hour1 * 60 + minute1;   ///虽然要求的是变量必须先要初始化=0，但是对于有公式可以算的变量，直接可以
	                                 ///定义为所需要的公式，简便，而对于那些需要被   人为赋值的变量如：代码中的hour1,minute1
	int t2 = hour2 * 60 + minute2;   ///就必须要先 初始化=0，当然这不是vs所强制要求的，而是基于  简便，易于查找，便于修改
	                                 ///所做出的决定！！！！！！！！！！
	int t = t1 - t2;

	int hour = t / 60;

	int minute = t % 60;

	printf("时间差为：%d时%d分", hour, minute);

	return 0;
}