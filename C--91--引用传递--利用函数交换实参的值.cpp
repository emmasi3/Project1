#include <iostream>
using namespace std;

void swap(int &a, int &b) 
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int a = 1;
	int b = 2;
	swap(a, b);
	//1. 这就是引用的好处  swap()函数中，形参 int &a =  a ---这很明显，是一个“引用”的使用，给变量 a 起别名 a ，可以是
	// 相同的， int &b = b; 也一样
	//2. swap(a,b); 调用函数时，其实是在 给 函数定义处的“形参”做“赋值”操作！！！，所以才有了引用的使用，相对于指针，
	// 好用一些，但是，指针的方法，必须熟练于心！！！
	cout << a << endl;
	cout << b << endl;

	system("pause");
	return 0;
}