#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	//读进整数位数N
	int N;
	printf("请输入：\n");
	scanf("%d", &N);
	//遍历所有N位数
	//i为需要判断的数字
	int i;
	for (i = pow(10, N - 1); i < pow(10, N); i++) {
		//替换
		int a = i;
		//读取i的每一位数字
		int b;
		int sum=0;
		for (a = i; a >= 1; a=a / 10) {
			b = a % 10;
			sum += pow(b, 3);
		}
		if (sum == i) {
			printf("%d\n", i);
		}
		sum = 0;
	}

	return 0;
}