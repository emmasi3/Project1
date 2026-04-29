#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int isprime(int i) 
{
	int n = 0;
	int a;
	int N = 0;

	for (n = 2; n < i; n++) {
		a = i % n;
		if (a == 0) {
			N++;
		}
	}
	return N;
}

int main()
{
	
	int x;

	printf("请输入：\n");
	scanf("%d", &x);

	int y = x;
	int i;
	
	int n = 0;
	int a;
	int N = 0;

	if (x == 1) {
		printf("1以内无素数");
	}
	else {
		printf("%d以内的素数有：", x);
	}

	for (i = 2; i <= y; i++) {

		N = isprime(i);//此处为利用己“定义的函数”进行N的赋值，函数输出的值的类型--由return *决定，如果没有return 
		             //那么 在定义函数时，--用void--替换int 进行定义，默认返回值 类型为 void--
		if (N == 0) {
			printf("%d,", i);
		}
		N = 0;
	}

	printf(" \n");
	printf("%d以内的素数查找完毕", x);
	return 0;
}/*总结：1. 格式：int 函数名(类型 变量名，~~~，不断重复要输入的变量)
                 {
                     主体--；
			         return 返回值；--此时返回的一般为int 类型--如return 0;
		         }
		2. 格式：void f(x)(int i,intx,int y,,,)
		         {
				      主体；
					  这个时候可以不用return ,因为void会自动默认返回值类型为void
				 }
		3. 函数中要用到的变量，必须在函数中定义（除了，要求“从外部”“输入进”函数的常量除外），否则会报错
		*/