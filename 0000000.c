#include <stdio.h>
int main()
{
	int a = 3;
	int b = 3;
	b = ++a;
	printf("%d,%d\n", a, b);

	b = a++;
	printf("%d,%d\n", a, b);

	return 0;
}