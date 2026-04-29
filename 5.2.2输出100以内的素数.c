#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//计算x以内的素数，可以是100
	int x;

	printf("请输入：\n");
	scanf("%d", &x);

	int y = x;
	int i;
	//记录判断i是否为素数的次数
	int n = 0;
	int a;
	int N = 0;

	if (x == 1) {
		printf("1以内无素数");
	}
	else {
		printf("%d以内的素数有：", x);
	}

	for (i = 2; i <= y; i++) {
		for (n = 2; n <i; n++) {
			a = i % n;
			if (a == 0) {
				N++;
			}
		}
		if (N == 0) {
			printf("%d,", i);
		}
		N = 0;//记得初始化，不然i=4判断完之后，N=1会加入到下一次的循环，影响后面的程序，使得N不能等于0
	}

	printf(" \n");
	printf("%d以内的素数查找完毕",x);
	return 0;
}