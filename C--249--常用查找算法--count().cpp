#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	bool operator==(const Person& p)const //1.这个位置是最容易错的 ！！！记得加上 2 个const,否则有时候会报错
	{
		return this->age == p.age;
	}

	string name;
	int age;
};

void myprintf(const Person& p)
{
	cout << "姓名：" << p.name << "年龄：" << p.age << endl;
}

void test01()
{
	//1.内置数据类型
	vector<int>v;
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(8);
	v.push_back(10);
	v.push_back(3);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 3);
	cout << num << endl;

	//2.自定义数据类型

	vector<Person>vv;

	string m_name = "ABCDE";
	string name;
	int age = 0;
	for (int i = 0; i < 5; i++)
	{
		name.append(m_name, i, 1);
		age = rand() % 2 + 15;
		vv.push_back(Person(name, age));
		name = "";
	}

	for_each(vv.begin(), vv.end(), myprintf);
	cout << endl;
	//自定义数据类型，编译器不知道怎么比？如何？
	//看一看 count 底层是怎么作比较的，重载相应的符号就可以了！！！
	//但是，在哪儿重载呢？实在类中，还是在全局中？

	//count 底层利用for（） 循环比较，必然会用到， p == v[] 的操作，所以 p.operator==(v[]), 看清楚了吗？
	//所以：应该对 p 所在的类，做重载符号，才能在底层发挥效果！！！
	int Num = count(vv.begin(), vv.end(), Person("张三", 15));
	cout << Num << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	system("pause");
	return 0;
}