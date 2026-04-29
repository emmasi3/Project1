#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int one, two, five;
	//所要凑齐的金额（整数）
	int x;
	printf("请输入：\n");
	scanf("%d", &x);
	//记录组合的金额数
	int a;
	//只需一个组合时
	int N = 0;

	for (one = 1; one < 10; one++) {
		for (two = 1; two < 10; two++) {
			for (five = 1; five < 10; five++) {
				a = one * 1 + two * 2 + five * 5;//注意 a 的单位是（角）
				if (a == x * 10) {
					printf("%d张1角+%d张2角+%d张5角=%d元\n", one, two, five,x);
					N++;
					break;
				}
				a = 0;
			}
			if (N == 1)
				break;
		}
		if (N == 1)
			break;
	}

	printf("%d元的凑法如上所示\n",x);

	return 0;
}/*总结：1. 凑东西，尤其是有关于组合之类的，直接无脑用循环的“嵌套”
         2. break的作用范围是：跳出当前所在的循环，只退出最近的一个循环，如果是嵌套函数，如上，要细节detail
		 */