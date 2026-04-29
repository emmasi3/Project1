#include <stdio.h>

int main()
{
	int a = 5;
	int b = 6;
	int t;

	t = a;                        //此处为交换变量a,b 的值，如果直接写为：
	a = b;                        //                a=b; b=a;因为程序的执行有顺序，所以当执行了a=b时，a=6=b
	b = t;                        //                但是接下来，b=a,会得到b=a=6,无法达到交换值的程度。。。所以
	printf("a=%d,b=%d", a, b);    //需要一个新的变量  --或者叫它（盒子），放数据的容器！！！暂时放a的值，在后面可以
	                              //给b赋予a刚开始的值
	return 0;
}