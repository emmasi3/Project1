#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
void sc(int a, int b);

int main()
{
	//定义数组
	int number[10];
	int i = 0;
	//给每一个元素=0；初始化
	for (i = 0; i <= 9; i++) {
		number[i] = 0;
	}
	int count;
	scanf("%d", &count);

	while (count != -1&&count>=0&&count<=9) {
		number[count]++;
		scanf("%d", &count);
	}

	int t;
	for (t = 0; t <= 9; t++) {
		sc(t, number[t]);
	}
	
	return 0;
}
void sc(int a, int b) {
	printf("%d:%d次\n", a, b);
}
//感悟：1. “指针”定义数组一般用在，定义数组“容量”的时候，也就是设计马克杯的时候，至于以后的用数组/马克杯，用的是已经
//      定型的，这时候 number[i]已经可以使用了，因为这是在调用，或者写入，“并未改变马克杯的构造”