#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	int n = 0;

	scanf("%d", &x);

	do {
		x /= 10; /*do-while循环语句与while语句最大的区别是---首次进入循环时，是否需要判断？？do-while不需要判断，但
		但是后续需要判断，，而while则刚开始就要判断条件，，，*/
		n++;
	} while (x > 0);

	printf("%d", n);

	return 0;
}/*  1.  do-while循环必定能够执行 1 次，，，而while循环可能 1 次也不会执行！！！*/