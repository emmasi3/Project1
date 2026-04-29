#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	int y;
	printf("请输入：\n");
	scanf("%d %d", &x, &y);
	//处理
	int i = 2;
	int a;
	int b;
	int max;
	//
	if (x < y) {
		for (i = 2; i <=x; i++) {
			a = x % i;
			b = y % i;
			if (a == b && a==0) {
				max = i;
			}
		}
	}
	else {
		for (i = 2; i <=y; i++) {
			a = x % i;
			b = y % i;

			if (a == b&&a==0) {
				max = i;
			}
			//if (a == b) {
			//	if(b==0)
			//}             同时满足两个条件也可以这样写**
		}
	}


	printf("%d和%d的最大公约数：%d\n", x, y, max);

	return 0;
}