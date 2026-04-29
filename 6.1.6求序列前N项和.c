#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int N;
	printf("请输入：\n");
	scanf("%d", &N);
	//
	int a=2;
	int b = 1;
	double sum = 0;
	int aa;
	//
	int i = 1;

	for (i=1;i<=N;i++) {
		sum += a * 1.0 / b;
		aa = a;

		a = a + b;
		b = aa;
	}
	double c = 3.15;
	printf("%.2f\n", sum);
	printf("%.1f\n", c);
	return 0;
}/*总结：1. 要舍去小数点后面的几位，
            printf("%.xf",n)
			其中，x为要保留到的位数（小数点后）
			必须是%....小数点不能忘
			f也不能忘
		2.  这种方法 ；；不能“四舍五入”！！！！！！！！！！！
		*/