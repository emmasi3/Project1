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

	/*
	* 1、进行测试：直接同步，看是否是从github上拉去下来后，直接覆盖掉本地文件
	* 
	*/

	return 0;
}