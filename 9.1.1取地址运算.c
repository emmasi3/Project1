#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>


int main()
{
	printf("%ld\n",(int)sizeof(int));
	printf("%d\n", (int)sizeof(int));
	//额···结果没什么区别，long long类型专用，重点是后面的d
	// 
	// 1. sizeof()的返回值类型---void就是无类型，所以使用的时候，最好“强制类型转化”-- (int)sizeof(x)
	int x;
	printf("请输入：\n");
	scanf("%d", &x);
	// 2. &--是and符号，是C语言中的一种“运算符”，可以得到“x”变量的“地址”，&x--解释为：返回 变量x的地址（十六进制一般）
	printf("%p\n", &x);
	// 3. %p,是十六进制的结果，类型仍然是 int 类型，而%x，在很多情况下，与%p结果相似，甚至一致！！！
	//    但是用 %p,最好，网上查到的，看不太懂！
	// 
	// 4. %p,%x,在结果上最大的区别大概是---%p自动显示 0x前缀，而%x不行
	int a[3] = {1,2,3};
	int i;
	for (i = 0; i < 3; i++) {
		printf("%p\n", &a[i]);
	}
	// 5. 数组a[0]也可以作为变量，用“&”读取地址
	printf("%p\t", a);
	printf("%p\t", &a);
	// 5.5 &a和直接输入a数组，好像结果是一样的

	printf("%p\n", &a[0]);
	// 6. 当然，也可以读取“整个数组”-- &a--这不是读取每一个单位，而是读取a[]中，第“1”个位置的“地址”
	//    打印结果与 a[0] 一致！！！
	return 0;
 }