#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>
int main()
{
	
	int array[3][5] = {[0][0]=0,[1][4]=8};
	// 1. 这是第一种设置二维数组的方法--直接赋值，其余填充为0！！
	// 2. 还可以：： int array[][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};这样来定义数组00，这个时候，行数可以不写，但是
	//   “列数”-- 必须要写！！！！！！！
	// 3. 但是，如果要如2所示定义二维数组，没有填充的单位，“不会”自动补为0 ，***，
	// int array[][5]={{1,2,3,4,5},{1,2,3,4,5}};   如果printf("%d\n",array[2][0]);则结果为 -898989··什么的，也就是
	// 没有自动填充为0！！！
	// 4. int array[3][5]=`··,定义二维数组时，“3,5代表--3行5列”，但是
	//    array[2][4]==第“3行5列”的数字，而不是array[3][5]这表示的是 第“4行6列”使用数组时，一切以 0作为开头！！！
	
	
	
	printf("%d %d\n", array[0][1],array[1][4]);
	//遍历数组--二维
	int i;
	int j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			if (j == 4) {
				printf("%d\n", array[i][j]);
			}
			else {
				printf("%d\t", array[i][j]);
			}
		}
	}

	return 0;
 }