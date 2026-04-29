#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	printf("请输入自变量的值：\n");
	scanf("%d", &x);

	int F;//编一个有关分段函数的程序

	if (x < 0) {
		printf("当x=%d时，函数值为：%d\n", x,-2 * x);
	}
	else if (x == 0) {
		printf("当x=%d时，函数值为：%d\n", x, 0);
	}
	else {
		printf("当x=%d时，函数值为：%d", x, 2 * x);
	}

	return 0;
}
/*总结：1.  一般的也就是标准的if-else结构为：
            if()
			{
             1111   
			}
			else
			{
			 0000
			}
			这样写是标准的，但如果是嵌套的if-else函数，如果你在每一个else后面加上{}，那么整体上，所有的程序都会
			向右偏移，这是不美观的，但这样也是可行的
		2.  那么为了解决这个问题，前人便使用
		    if(){
                000
			}esle if   //这里是直接跟if没有{}，但是if后面都要跟{},而在 级联中  else统一不带{}！！！
*/