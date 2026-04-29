#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	int y;
	printf("请输入：\n");
	scanf("%d %d",&x,&y);

	int t;

	while (y > 0) {
		t = x % y;

		if (t == 0) {
			break;
		}
		x = y;
		y = t;
	}

	printf("%d\n", y);

	return 0;
}
/*总结：   辗转相除法-----我没理解，但是知道基本的算法
           2. 如果没有最大公约数的话，那么程序将会输出  “1”而“不会”报错！！！！！！*/