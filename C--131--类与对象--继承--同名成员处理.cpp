#include <iostream>
using namespace std;

class base
{
public:
	int a = 10;

	void f1()
	{
		cout << "base函数调用" << endl;
	}
};

class son:public base
{
public:
	int a = 20;
	void f1()
	{
		cout << "son函数调用" << endl;
	}
};

void test01()
{
	base b1;
	son s1;
	cout << s1.a << endl;       // 1.直接用 s1.a 访问的是子类的 a 成员，想要访问父类的 a 同名成员
	cout << s1.base::a << endl; //  .只需要加作用域就可以访问

	s1.f1();                    // 2.“同名”成员函数也一样，也需要加作用域
	s1.base::f1();
}

int main()
{
	test01();

	system("pause");
	return 0;
}