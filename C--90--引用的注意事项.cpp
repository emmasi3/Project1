#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;
	//1. 这是正确的引用的创建方式，但是 错误的是；；； int& b;---先创建一个引用，这是不行的，也就是说：
	// . 引用不能初始化

	int c = 20;
	b = c;
	//2. 原本是想，将 b 再次作为 c 的引用使用，但是，没有那种写法！！！所以：
	// . 引用在创建后，不能再次更改！！！

	system("pause");
	return 0;
}