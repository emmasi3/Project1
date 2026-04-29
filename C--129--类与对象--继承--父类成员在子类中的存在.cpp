#include <iostream>
using namespace std;

class DAD
{
public:
	int a = 10;
public:
	int b = 20;
public:
	int c = 30;
};


class SON:public DAD
{
public:
	int a = 100;
};

void test01()
{
	cout << sizeof(SON) << endl; // 1. 这里的结果为--》 16 ，并不只有 SON 自己的成员变量，父类中的私有成员，也被继承，
	                             //  . 但是，父类中的私有成员子类却不能调用！！！
}

int main()
{
	test01();

	system("pause");
	return 0;
}