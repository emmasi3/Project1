#include <iostream>
using namespace std;

class Person
{
public:
	//1. 一般对属性初始化
	/*Person(int a, int b, int c)
	 {
		 A = a;
		 B = b;
		 C = c;
	 }*/

	//2. 用列表初始化
	Person(int a, int b, int c) :A(a), B(b), C(c)
	{

	}
	// . 电脑会自动执行，如 1 般的赋值操作 Person(int a, int b, int c) : A(a), B(b), C(c) {}   冒号，大括号，都不能忘记

	int A;
	int B;
	int C;
};

void test01()
{
	Person p(10, 20, 30);
	cout << p.A << "  " << p.B << "  " << p.C << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}