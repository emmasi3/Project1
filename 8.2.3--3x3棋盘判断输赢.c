#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>

int main()
{
	int array[3][3];
	//行
	int i;
	int j;
	int num0 = 0;
	int num1 = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (array[i][j] == 0) {
				num0++;
			}
			else if (array[i][j] == 1) {
				num1++;
			}
			if (num0 == 3 || num1 == 3) {
				printf("胜负已分\n");
				goto out;
			}
		}
	}
out:

	return 0;
}