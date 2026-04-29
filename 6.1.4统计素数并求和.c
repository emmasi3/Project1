#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int M=0;
	int N=0;
	//[M,N]
	printf("ÇëÊäÈë£º\n");
	scanf("%d %d",&M,&N);
	//
	int m = M;
	//ÅĞ¶ÏËØÊı
	int i = 2;
	int n = 0;
	int nn = 0;
	//
	int sum = 0;
	//
	for (m = M; m <= N; m++) {
		for (i = 2; i < m; i++) {
			if (m % i == 0) {
				break;
			}
			else {
				n++;
			}
		}
		if (n==m-2||m==2) {
			sum += m;
			nn++;
		}
		n = 0;
	}

	printf("%d %d", nn, sum);

	return 0;
}