#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//结尾 N * N。
	int N;
	printf("请输入：\n");
	scanf("%d", &N);
	//
	int i = 1;
	int h;
	int j;
	int n = 0;
	//
	for (i = 1; i <= N; i++) {
		for (h = 1; h <= i; h++) {
			j = i * h;
			n++;
			//
			if (h == 3 && i == 3) {
				printf(" %d*%d=%d\n", h, i, j);
			}
			else if (h == 3 && i == 4) {
				printf(" %d*%d=%d    ", h, i, j);
			}
			else if (n != i) {
				printf("%d*%d=%d    ", h, i, j);
			}
			else if (n == i) {
				printf("%d*%d=%d\n", h, i, j);
			}
		}
		//别忘了两边清零--0
		n = 0;
	}

	return 0;
}