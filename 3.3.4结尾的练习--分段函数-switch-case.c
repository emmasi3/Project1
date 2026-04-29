#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double x = 0;
	printf("请输入自变量的值：\n");
	scanf("%lf", &x);

	int b = x / x;//////再次加深一下理解：int b实际上就是int x/x,而x/x是有结果的为double类型，他会自动将double转化为
	////////////////////////////////////////////////////////////////////int类型，也就是舍去小数部分，只保留整数部分**

	switch (b) {
	case -1:
		printf("x=%lf时，值为%lf\n", x, -2 * x);
		break;
	case 1:
		printf("x=%lf时，值为%lf\n", x, 2 * x);
		break;
	default:
		printf("x=0时，值为0\n");
		break;
	}
	int c = 10.2;
	printf("%d\n", c);/////结果是10 懂否？？？？

	return 0;
}