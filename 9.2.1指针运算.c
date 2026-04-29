#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>

int main()
{
	char p1[] = { 1,2,3,6,5,9 };
	printf("%p\t", p1);
	printf("%p\n", p1 + 1);

	int p2[] = { 1,2,3,5,6,8 };
	printf("%p\t", p2);
	printf("%p\n", p2 + 1);
	// 1. 所谓的"p2+1"也就是“地址”+1，不是纯数字相加，+1的意思-- 移动一个“单位”，也就是从上一个地址，移动到下一个
	//  . 地址，
	//  . 但是，char 和 int +1，之后的变化是不一样的，char 移动了 1 字节，而 int 移动了 4 字节，why?
	//  . 因为 sizeof(char)==1,sizeof(int)==4,一个单位的占据空间就是这样，决定了 p+1 的数字上的幅度，但是
	//  . 含义依然是，移动到下一个单位
	int* p = p2;
	printf("%d\n", *p);
	printf("%d\n", p[0]);
	printf("%d\n", *( & p2[0]));
	printf("%d\n", *(p+1));
	// 2. 同上，* 用来调取（p+1）地址上的“值”，所以最后打印的是，下一个单位的“值”，也就是--> p1[1]
	//  . 所以，可以用这种方式，遍历整个数组（被 p 指向的）
	int n;
	for (n = 0; n < sizeof(p2) / sizeof(p2[0]); n++) {
		if (n == sizeof(p2) / sizeof(p2[0])-1) {
			printf("%d\n", *(p + n));
		}
		else {
			printf("%d\t", *(p + n));
		}
	}
	//  . 这是对于，*(p+n)的拓展，*(p++),地址+1，-->向后移动一个单位，， “-”则是向前移动一个单位
	//  . 当然还有---  "p--"
	//  . 如下所示，p++后的地址，大小“绝对大于”前一个 ！！！
	int zuigaowei = sizeof(p2) / sizeof(p2[0]);
	for (p; p <= &p2[zuigaowei - 1]; p++) {
		if (n == &p2[zuigaowei - 1]) {
			printf("%d\n", *p);
		}
		else {
			printf("%d\t", *p);
		}
	}

	return 0;
}