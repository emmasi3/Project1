#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("请输入月份：\n");
	int month;
	scanf("%d", &month);
	// 1. 用char a[][]；“二维数组”--“字符 "串" 数组”做
	char a[][10] = {
		"January","February","March","April","May","June","July","August",
		"September","October","November","December",0
	};
	printf("%s\n", a[month-1]);
	/*
	* 解读：a[][10]中，10代表“列”也就是这个数组“每一行最多能容纳10个单位的东西”因为是char 所以每一行最多容纳10 字节
	* 2.在printf()时候，  a[1] 代表第二行的全部内容（单位），也就是会输出第二行的东西，也就是February,而 a[0][0]
	*  . 则会输出  J ,单个字符，而不是字符串，当然 J 需要用 "%c"输出
	*/

	// 3. 用char *p[];
	char* p[] = { &"January",&"February",&"March",&"April",&"May",&"June",
		&"July",&"August",&"September",&"October",&"November",&"December",
	};
	printf("%s\n", p[0]);

	return 0;
}