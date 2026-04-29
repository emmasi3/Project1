#include <stdio.h>

void swap(int a, int b);
//
int main()
{
	int a = 5;
	int b = 6;
	swap(a, b);
	if (a < b) {
		int a = 10;
		printf("%d\n", a);
	}

	printf("将换后为：%d,%d\n", a, b);

	return 0;
}
//
void swap(int a, int b) {
	int t;
	t = b;
	b = a;
	a = t;
}
/*总结：1. 本地变量-定义--你见过的所有变量都是，包括赋值给变量的参数，也是
        2. 本地变量-规则-
	   （1） bd变量需要定义在“块”内（快就是一对“{}”）
	   （2） “块”--可以是“函数”的，也可以是“语句”的，比如
	   （） if(){
	          int a=0;
			  printf("%d",a);
	        }语句中，可以打印 ,a=0
			但是在if之外“紧跟”一个printf，就打印不出来"a=0"
	   （3） 如果在一个函数中“上层“已经定义了变量a=10,那么在if 之内的pritnf()则“依旧打印a=0”,而紧跟着，在函数外
	   pritf()则会打印与，printf()在同一“块”内的a，也就是a=10
	   （4） 一旦编译器没到达“块”内，或者已经“出去”，那么对于块中的变量也就随之结束，也就是“找不到了”*/