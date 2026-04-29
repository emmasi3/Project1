#include <iostream>
using namespace std;

class base1
{
public:
	int a = 10;
};

class base2
{
public:
	int a = 20;
};

class son:public base1,public base2   // 1. 这种格式是“多继承”的写法
{
public:
	int a = 30;
};

int main()
{
	//2. 问题也很明显，想要调用准确的同名不同类的成员，需要添加作用域，这是很麻烦的，添加不好就导致工作困难，所以不建议
	// . 较多的使用多继承的语法

	system("pause");
	return 0;
}