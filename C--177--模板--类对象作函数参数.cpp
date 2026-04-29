#include <iostream>
using namespace std;

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	T1 name;
	T2 age;

	void show()
	{
		cout << this->name << "\t" << this->age << endl;
	}
};

//1.指定传入类型（也是用的最多的方式，不然太烦了）
void f1(Person<string, int>&p)
{
	p.show();
}

void test01()
{
	Person<string, int>p("张三", 10);
	f1(p);
}

//2.参数模板化
template<class T1,class T2>
void f2(Person<T1, T2>& p)//这里实际上相当于“函数模块”和上面的“T1, T2”不同
{
	p.show();
}

void test02()
{
	Person<string, int>p("张三", 10);
	f2(p);
}

//3.整个类模块化
template<class T>
void f3(T& p)
{
	p.show();
}
void test03()
{
	Person<string, int> p("张三", 10);
	f3(p);
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	cout << endl;

	system("pause");
	return 0;
}