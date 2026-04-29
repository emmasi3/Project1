#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int A;
	printf("请输入：\n");
	scanf("%d", &A);
	//
	int x;
	int y;
	int z;
	//
	int t;
	//
	int n = 0;
	for (x = A; x <= A + 3; x++) {
		for (y = A; y <= A + 3; y++) {
			for (z = A; z <= A + 3; z++) {
				if (x != y && x != z && y != z) {
					t = x * 100 + y * 10 + z;
					n++;
					if (n < 6) {
						printf("%d ", t);
					}
					else {
						printf("%d\n", t);
						n = 0;
					}
				}
			}
		}
	}

	return 0;
}/*总结：1.  垃圾，--当然指的是“我”菜；；哎，
         2.  以后遇见组合给定数字，并且，没有重复的时候，-----全部遍历，舍去重复，剩下答案--！！！*/