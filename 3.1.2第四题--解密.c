#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0;
	printf("请输入错误的十进制数：\n");
	scanf("%d", &a);

	printf("原本的BCD数为：%x", a);   //%d为整数类型，但是%x也为整数类型，，但是%x表示的是16进制的整数！！！

	return 0;
}//////////所谓BCD数，其实就是一个给定的十进制数，如：18，转化为二进制数：0001 0010后；看4个0中1位于--哪一位--
///////////就输出他的  --位数--即可，如BCD：18=0001 0010--12--此为BCD数