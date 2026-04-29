#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double a = 1234.5678;
	printf("%f,%e", a, a);// %e 或者 %E 都会输出1.···(e/E+03)这是--表示 10^3次方的！！科学计数法

	return 0;
}