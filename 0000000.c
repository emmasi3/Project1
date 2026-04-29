#include <stdio.h>
int main()
{
	int a = 3;
	int b = 3;
	b = ++a;
	printf("%d,%d\n", a, b);

	b = a++;
	printf("%d,%d\n", a, b);

	printf("你好");
	printf("开始");

	return 0;
}