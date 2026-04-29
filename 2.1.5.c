#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	const int AMOUNT = 100;
	int price = 0;
	int sum = 0;

	printf("请输入金额：");
	scanf("%d",&price);

	sum = AMOUNT - price;
	printf("找您%d元\n",sum);

	///以下是一个可以展现计算式子的程序
	int a = 0;
	int b = 0;
	
	printf("请输入所需计算值：");
	scanf("%d %d", &a, &b);
	printf("%d*%d=%d", a, b, a * b);

	return 0;
}

///一般对于给定的程序之内的 不变量，也就是这里的100元，一般不直接出现100，而是在 const int AMOUNT=100; 直接定义一个
///不变量也就是常量，用   const   ---意为不变的用来修饰int 
/// 好处：1.便于以后的修改
///       2.便于其他人明白100的含义，而不至于疑惑为什么有100出现
/// 
