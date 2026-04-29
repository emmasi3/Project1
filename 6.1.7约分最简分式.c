#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	/*int a = 16, b = 13;
	int t;
	int i = 1;

	do {
		t = a % b;
		a = b;
		b = t;
	} while (t != 0);        //这是辗转相除法，没有(1,n)之间的公约数时，的结果---- 1，即为最大公约数；
	printf("%d", a);*/    
	int a, b;
	scanf("%d/%d", &a, &b);
	//余数
	int t;
	//替换
	int A = a, B = b;
	do {
		t = A % B;
		A = B;
		B= t;
	} while (t != 0);
	
	printf("%d/%d化简后：%d/%d\n", a, b, a / A, b / A);

	return 0;
}