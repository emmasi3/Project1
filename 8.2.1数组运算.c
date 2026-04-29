#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
int search(int x, int a[], int length);

int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10,12,13,14,100 };
	printf("%d\n", sizeof(a) / sizeof(a[0])); //数组元素个数的计算
	//
	int x;
	printf("请输入要查找的数字的位置\n");
	scanf("%d", &x);
	//
	int N;
	N = search(x, a, sizeof(a) / sizeof(a[0]));//此N非 search里面返回的N，因为这是在不同的“块”内！！！

	if (N != -1) {
		printf("%d的位置：在a[%d]\n", x, N);
	}
	else {
		printf("%d不在a[]内\n", x);
	}
	//
	int b[sizeof(a) / sizeof(a[0])];//int b[]=a;这是错误的代码，不能直接将数组整体赋值
	int i;                    //仅有的方法：遍历数组，然后赋值给每一个单位
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		b[i] = a[i];
	}
	//
	printf("%d\n", b[0]);
	//
	int c[10] = {[0]=0};//定义数组时，如果c[10]明确了数组容量，而只给出某一位[0]=1,那么其余位置都自动填充为“0”！
	printf("%d\n", sizeof(c) / sizeof(c[0]));//这就给数组的元素，全部初始化为“0”提供了方便！
	for (i = 0; i < 10; i++) {      //只需要int c[10]={[0]=0};就可以完成数组的定义及“初始化”，
		printf("%d\t", c[i]);      //当然，有时候只要求数组中某几个位置为“特殊值”，则可以
	}                            //   int c[10]={[0]=1,[3]=8,[9]=4};   这要可以简化很多输入！！！

	return 0;
}

int search(int x, int a[], int length) {
	int i;
	int N = -1;
	for (i = 0; i < length; i++) {
		if (a[i] == x) {
			N = i;
			break;
		}
	}
	return N;
}