#include <iostream>
using namespace std;

void f(int a, int) {
	cout << "hello,world" << endl;
}
void ff(int a, int=10) {
	cout << "hello,world" << endl;
}
int main()
{
	f(10, 1);
	//1. 直接在“形参列表”中输入数据类型，就可以定义一个占位参数，目前看来，用不到
	ff(10);
	//2. 占位参数也可以有默认值-- 直接 int =10 ;就可以了，
	// . 在调用的时候必须传输f(10,1) ;输入一个占位参数的值，当然
	// . 在游客占位默认值的时候，不用传入也可以

	system("pause");
	return 0;
}