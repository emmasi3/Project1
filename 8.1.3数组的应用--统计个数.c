#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
void sc(int a, int b);

int main()
{
	int type;
	int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;
	scanf("%d", &type);

	while (type != -1) {
		switch (type) {
		case 0:
			n0++;
			break;
		case 1:
			n1++;
			break;
		case 2:
			n2++;
			break;
		case 3:
			n3++;
			break;
		case 4:
			n4++;
			break;
		case 5:
			n5++;
			break;
		case 6:
			n6++;
			break;
		case 7:
			n7++;
			break;
		case 8:
			n8++;
			break;
		case 9:
			n9++;
			break;
		}
		scanf("%d", &type);
	}
	printf("已统计完毕\n");
	sc(0, n0);
	sc(1, n1);
	sc(2, n2);
	sc(3, n3);
	sc(4, n4);
	sc(5, n5);
	sc(6, n6);
	sc(7, n7);
	sc(8, n8);
	sc(9, n9);
	return 0;
}
void sc(int a, int b) {
	printf("%d:%d次\n", a, b);
}