#include <iostream>
using namespace std;
#include "Person.cpp"

template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age);

	void show();

	T1 name;
	T2 age;
};
template<class T1,class T2>    //1.这是构造函数的类外实现，Person<T1,T2>:: 这是为了指明该构造函数是哪一个类模板的
Person<T1, T2>::Person(T1 name, T2 age)//意为：该函数定义是--- 类模板Person<T1,T2>的，
{                                     //而没有 <T1,T2>那就是一个普通类的函数定义，
	this->name = name;
	this->age = age;
}
template<class T1,class T2>
void Person<T1, T2>::show()    //2.成员函数的类外声明也是一样的道理
{
	cout << this->name << "  " << this->age << endl;
}

void test01()
{                              //3.这个template<class T>是每次都要写的，只能作用于“它的底下最近的一个对象”！！！
	Person<string, int> p("张三", 18);
	p.show();
}


int main()
{
	test01();

	system("pause");
	return 0;
}