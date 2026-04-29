#include <iostream>
using namespace std;

int main()
{
	//1. 引用的基本语法 --- 数据类型 &别名 = 变量名
	int a = 10;
	int& b = a;

	cout << a << endl;
	cout << b << endl;

	b = 20;
	cout << a << endl;
	cout << b << endl;
	// . 唯一的用途，给变量 a 起别名，也就是 b=a=10; 如果直接用 b=a; 来执行，改变 b 的大小并不能改变a 的大小



	system("pause");
	return 0;
}