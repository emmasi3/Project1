#include <iostream>
using namespace std;
#include <string>

// 1.问题：要判断 对象 p1 == p2 是用什么标准判断的？具体怎么实现比较，返回什么结果？

class Person
{
public:
	void operator==(const Person& p2)
	{
		if (this->age == p2.age)
		{
			cout << this->name << "与" << p2.name << "年龄相同" << endl;
		}
		else
		{
			cout << this->name << "与" << p2.name << "年龄不相同" << endl;
		}
	}
public:
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
private:
	string name;
	int age;
};

void test01()
{
	Person p1("张三", 18);
	Person p2("李四", 20);
	p1 == p2;
}

int main()
{
	test01();

	system("pause");
	return 0;
}