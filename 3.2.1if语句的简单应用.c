#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入初始时间：\n");
	scanf("%d %d", &a, &b);

	int c = 0;
	int d = 0;
	printf("请输入流逝时间：\n");
	scanf("%d %d", &c, &d);

	int hour = a + c + (b + d) / 60;
	int minute = (b + d) % 60;///但这样的程序会遇到一个问题，当输入负的时间时，会可能显示 10点-10分。。

	if (minute < 0)
	{
		minute = 60 + minute;
		hour--;
	}///当添加了 if语句之后事情就变得简单可以解决了！！，注意  if()函数和 main()有相似之处，if()之后不加  ；而是 { }！！

	printf("现在的时间为：%d时%d分", hour, minute);

	return 0;
}
/////////////总结一下：：1.  if() 语句，格式为：    if(执行体)            ----注意了，if()后面没有-- ；--分号！！！！
/////////////                                           {
/////////////                                              内容；
/////////////                                              内容；
/////////////                                           }