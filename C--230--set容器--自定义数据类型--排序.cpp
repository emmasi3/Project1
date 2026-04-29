#include <iostream>
#include <string>
#include <set>
using namespace std;

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

class mycompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.age > p2.age;
	}
};

void test01()
{
	set<Person, mycompare>s;//1.利用 set 容器储存自定义数据类型的时候，要指定排序的规则，否则无法插入数据
	Person p1("张三", 18); //2.方法，和上一节的 set 容器排序一毛一样，自己去看
	Person p2("李四", 25);
	Person p3("王五", 34);
	Person p4("赵六", 19);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, mycompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it).name << "  " << (*it).age << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}