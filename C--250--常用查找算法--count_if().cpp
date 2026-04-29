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
	string name;
	int age;
};

void myprintf(int v)
{
	cout << v << " ";
}

void myprintff(const Person& p)
{
	cout << "姓名：" << p.name << "年龄：" << p.age << endl;
}

class countif
{
public:
	bool operator()(int v)
	{
		return v < 6;
	}
};

class f
{
public:
	bool operator()(const Person& p)const
	{
		return p.age == 15;
	}
};

void test01()
{
	//1.内置数据类型
	vector<int>v;
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myprintf);
	cout << endl;

	int num = count_if(v.begin(), v.end(), countif());
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
	cout << "------------------" << endl;
	for_each(vv.begin(), vv.end(), myprintff);

	int numm = count_if(vv.begin(), vv.end(), f());
	cout << numm << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}