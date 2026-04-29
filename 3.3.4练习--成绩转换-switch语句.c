#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int grade = 0;
	printf("请输入您的成绩：\n");
	scanf("%d", &grade);

	int a = grade / 10;

	switch (a) {
	case 10://这里100分可以单独罗列出来，并且，给case 10:下属部分留白，以便于和case 9：执行同一个结果--A
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
		break;
	case 7:
		printf("C");
		break;
	case 6:
		printf("D");
		break;
	default:
		printf("E");
		break;
	}

	return 0;
}
/*总结：1. 这种方法好就好都在他直接 跳过不必要的 经历（步骤）
        2. 但是差就差就在 必须得有 常量  ，这就大大限制了它直接被编好的速度，
		但是只要掌握了，就可以很熟练地 用不同的方式  转化--- -已知量（不是int 类型的）为--int类型的case常量！！，
		3. 这是由你自己想出来的，没看网课哦···棒棒哒--*/