#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	const int x = 58;
	int f;
	printf("请输入您所猜的数字：\n");
	scanf("%d", &f);
	int n = 0;

	if (f == x) {
	}
	else {
		while (f != x) {
			n++;

			if (f < x)
				printf("您猜小了\n");
			else
				printf("您猜大了\n");

			printf("请您再猜:\n");
			scanf("%d", &f);
		}
	}
	n++;
	printf("恭喜您，猜对了！\n");
	printf("您一共猜了%d次", n);

	return 0;
}