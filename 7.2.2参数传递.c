#include <stdio.h>

void swap(int a, int b);
//
int main()
{
	int a = 5;
	int b = 6;
	swap(a, b);
	printf("将换后为：%d,%d\n", a, b);//想要利用一个函数swap()交换，a--b的值，但是这样行不通！！！
	                     /*reason::在一个函数中出现的变量a,与，在同一个程序中但，“不同函数”中出现的变量a
						 是不“同的”
						 换言之：：在swap()函数中“不能”对main()函数中的a,b动手脚，因为不同的函数有自己的
						 储存变量的空间！！！*/
	return 0;
}
//
void swap(int a, int b) {
	int t;
	t = b;
	b = a;
	a = t;
}
//到目前为止，还没有类似问题的解决方法，所以，不用太过焦虑。。！