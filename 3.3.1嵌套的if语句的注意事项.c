#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//比较三个整数的大小；
	int a, b, c;
	printf("请输入要比较的三个整数：\n");

	scanf("%d %d %d", &a, &b, &c);

	//开始比较
	if (a > b) {
		if (a > c) {
			printf("三者中最大数为:%d", a);/*if-else里面套if 就是if的”嵌套“语句，，，*/
		}
		else {
			printf("三者中最大数为:%d", c);
		}
	}
	else {
		if (b > c) {
			printf("三者中最大数为:%d", b);
		}
		else {
			printf("三者中最大数为:%d", c);
		}
	}

	return 0;
}
/*总结：1. 使用if-else语句时，要注意if-else后面尽量将    {}    带上，如果不带很可能会出错
        2. if-else的第二种形式，不带{}  的那种，如果有嵌套结构的话，else属于距离他自己  最近的  if 语句！！！！！
		       这是最容易错的
	    3.   而且对于2来说，，不要以为单纯的缩进可以解决问题，不可能的，电脑指挥一步一步往下走，但是你不缩进的话，绝对会
		报错！！！*/