#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>

int main()
{
	int a[] = { 9,8,7,5,6,4,1,2 };
	int* p = a;
	int* p1 = &a[3];
	printf("p1-p=%d\n", p - p1);
	printf("p1-p=%d\n", p1 - p);
	// 1. 这个结果一步一步分析--3‘’‘’‘’首先，p1-p为16进制的“地址”相加减，所以内部首先计算“地址的差值”，然后
	//  . 将结果转化为“10进制”，这时候，得到了“ 12 字节”，但是这里不会停止，继续 12/sizeof(int)=3,这才是最后的值
	//  . 得到了两个地址之间的“距离”，
	//  . 距离 有正负之分，所以 会有“-3”，因为 16进制的数字，说到底还是整数，还是有正负的
	//  . 如果想要 “数组储存的值”之间的差值，或者加值，则 需要 “*”调出“值”


	return 0;
}