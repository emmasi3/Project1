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
	* 2、现在，我在github仓库中直接修改本文件，并在之后
	* 	通过vs2026“拉取”github远端的该文件，看看会对本地的项目文件有什么影响？
	*/

	return 0;
}
