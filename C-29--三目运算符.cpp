#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	//1. 问题：给c 赋值，赋值a，b当中最大的。。。一般想法是用if条件语句，当然这样可以，但是还可以简单些
	c = (a > b ? a : b);
	// . 这样就可以了。。。。。。那么这个“表达式”返回的是什么东西呢？
	//2. 返回的是，"变量b"   !!!!!,返回值是“变量”，所以可以继续“赋值”
	(a > b ? a: b) = 400;
	cout << a <<endl<< b << endl;
	// . 这样就会给 b=400; 赋值！！！


	system("pause");
	return 0;
}