#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b;

	printf("请输入两整数：\n");
	scanf("%d %d", &a, &b);

	double c = (a + b) / 2.0;       //double 定义的变量c为小数类型，那么用=赋值的时候，就必须 赋 double类型的数字
	printf("两数平均值：%f\n",c);   //如果 写的是 (a+b)/2--，那么他会自动舍去小数部分，和整数类型挂钩
	                                //当然 原因：1.= 从右向左运算！！！！！，将右边的值赋给变量C
	return 0;                       //           
}