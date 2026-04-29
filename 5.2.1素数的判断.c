#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	printf("请输入：\n");
	scanf("%d", &x);

	int y = x;
//检验z==q，是否满足，满足即为素数**
	double z;
	int q;
//
	int A = 0;

//主要内容
	while (y> 2) {
		z = x * 1.0 / (y - 1);  /*我的判断方法：判断除了 （1。x）两数子 本身，用x除以  --[2,x-1]内的所有数字，
		                        用z记录真实值，用q记录int 整数值，如果x为素数，那么  q==z 这种情况必定存在
								所以用if语句中的  “ A ” 变量来记录次数（q==z的次数），（前提是int A=0;）如果x为素数，那么A!=0这是
								绝对的
								反之，循环结束后，A==0时 ，x   必定为 素数 */
		q = x / (y - 1);    
		y--;
		if (q == z)
			A++;
	}

	if (x == 1) {
		printf("1不是素数");
	}
	else if (A == 0) {
		printf("%d是素数", x);
	}
	else
		printf("%d不是素数", x);

	return 0;
}