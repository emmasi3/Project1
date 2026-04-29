#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 1;
	int N;
	printf("ÇëÊäÈë£º\n");
	scanf("%d", &N);

	int n = N;

	while (n > 0) {
		a = a*n;
		n--;
	}

	printf("%d!==%d\n", N, a);

	return 0;
}