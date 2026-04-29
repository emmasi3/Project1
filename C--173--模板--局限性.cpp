#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};


template<class T>
bool cmp(T &p1,T &p2) //1.一般来说，都是这样定义的函数模板，但是有个问题，如果传入的是 两个类对象 p1,p2，很明显代码报错了
{                     // .因为编译器不知道p1与p2 这个 自定义数据类型该如何比较？
	if (p1 == p2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<> bool cmp(Person& p1, Person& p2)//2.解决方法有两种：这是第一种，直接“重写”模板函数，将 T 直接写为 Person
{                                          // .这样就可以很好地解决问题，当执行cmp(p1,p2) 时，编译器会直接执行对类型的
	if (p1.name == p2.name && p1.age == p2.age)// .“重写”函数模板
	{                                    //上面是具体的语法，但是，类比于“子类重写父类的成员函数”，要加上“作用域”
		return true;                     //这里是用 template<> 来代替的，很相似
	}
	else
	{
		return false;
	}
}

void test01()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);

	int ret = cmp(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}