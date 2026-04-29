#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
	string Pname;
	Phone(string name):Pname(name){}
};

class Person
{
public:

	Person(string name, string Pname):name(name),a(Pname){}//为属性初始化

	Phone a;//成员属性,这里类对象，作为，类属性，
	string name;
};

void test01()
{
	Person p1("张三","华为 14 Pro Max");
	cout << p1.name << "拿着  " << p1.a.Pname << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}// 1. “子类”先被创造，然后才有父类
/// 2. 父类“析构函数”优先进行，“子类”最后