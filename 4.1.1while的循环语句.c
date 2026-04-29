#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a;
	printf("请输入整数：\n");
	scanf("%d", &a);
	///////判断 整数 有 几 位？？？
	int n = 0;

	if (a == 0) {/////////////////要切记，要考虑一些特殊值，0，10，100···尤其是0，如果没有if语句，那么a=0时结果为0
		printf("1");/////显然是错误的，“0时一位数”
	}
	else {
		while (a != 0) {  //这是循环语句while的基本格式，和其他的if-else,switch-case等等类似···没有什么亮眼的地方
			n++;
			a /= 10;       //个人感觉昂，--每次遇到比较难缠的东西时，好像都要考虑int 类型的--舍去小数--保留整数--的操作！~
		}                //我感觉以后要参加的  ACM  也绝对会遇到，而且绝对不少，所以得记好了所谓的int的性质！！

		printf("%d", n);
	}

	

	return 0;
}