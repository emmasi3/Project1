#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//这两行新的东西现在可以不用理解，用不上，只是为了让 计算机  生成随机数  提供数据库 而已。
#include <time.h>
int main()
{
	srand(time(0));//这两行也一样
	int a = rand();
	int x = a % 100 + 1;//余数永远小于除数，a为一个随机数，一般电脑生成的很大，为了“限制范围”，用“ 取余 ”的计算方法
	                    //将 要 猜 的数限制在 [0,100] 的范围内！！！！！这点非常重要，我有预感，以后绝对用得上
	int f;
	printf("请输入您所猜的数：\n");
	scanf("%d", &f);

	int n = 0;

	do
	{
		if (f == x){
		
		}
		else if (f < x) {
			n++;
			printf("很遗憾您猜“小”了，请您再猜:\n");
			scanf("%d",&f);
		}
		else if (f > x) {
			n++;
			printf("很遗憾您猜“大”了，请您再猜:\n");
			scanf("%d",&f);
		}
	} while (f != x);

	printf("恭喜您猜对了，您一共猜了%d次\n", n + 1);

	return 0;
}/*总结：1. “ 取余 ”可以限制所得数字的范围！！！
         2. if条件后的执行内容可以留白，意思是什么都不执行，即使满足if的条件，题目中有很大的用途！！！！*/