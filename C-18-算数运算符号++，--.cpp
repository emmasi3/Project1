#include <iostream>
using namespace std;

int main()
{
	int a = 3;
	int b = 3;
	b = ++a;
	cout <<a<<"," <<b<< endl;

	b = a++;
	cout << a << ',' << b << endl;
	//1. 很重要的一点，++，——和C语言一模一样，++a也是一种运算，对a的值做了修改！！！
	// . 这一点很重要！！！

	system("pause");
	return 0;
}