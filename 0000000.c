#include <stdio.h>
int main()
{
	int a = 3;
	int b = 3;
	b = ++a;
	printf("%d,%d\n", a, b);

	b = a++;
	printf("%d,%d\n", a, b);

	printf("到底是谁？");

	return 0;
}