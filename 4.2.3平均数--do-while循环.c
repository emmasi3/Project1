#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//次数
	int n = 0;
	//总和
	int sum = 0;
	//输入
	int M;
	printf("输入：\n");
	scanf("%d", &M);
	//判断==-1
	do
	{
		if (M == -1) {
			sum = -1;
			n = 1;
		}
		else {
			sum += M;
			n++;
			printf("请再次输入：\n");
			scanf("%d", &M);
		}
	} while (M!=-1);

	double avg = sum * 1.0 / n;

	printf("所求为：%lf\n", avg);

	return 0;
}