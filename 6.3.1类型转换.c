#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double a = 10.2;
	printf("%d\n", (int)a);

	return 0;
}/*总结：1. ------(要转换为的类型)原数----；
         类如：(int)10.2--的结果为：10--int变量
		 2. 但是要注意，这是具有“强制性”的指令，而且，一般的类型都有范围限制，很可能不会得到你想要的*/