#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;

	scanf("price%d,%d",&a,&b);   ///scan为浏览的意思，f 指的是格式化 。。。不用管这个

	printf("%d,%d\n", a, b);

	return 0;
}
///scanf() 函数  1. %d 为需要在终端输入的字符类型，而后紧跟  &  ----此为 and  作用目前不清楚，但是必须要跟，不跟会报错
///              2.此函数字符串内的 东西，除了  %d  外，其余的东西如:price,空格，---，---等都不能省略，否则会有bug