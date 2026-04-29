#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

class commend
{
public:
	bool operator()(Person p)
	{
		return p.age > 20;
	}
};

void myprintf(Person p)
{
	cout << "姓名：" << p.name << " " << "年龄：" << p.age << endl;
}

void test01()
{
	vector<Person>v;
	v.push_back(Person("张三", 18));
	v.push_back(Person("李四", 27));
	v.push_back(Person("王五", 25));
	v.push_back(Person("赵六", 12));
	v.push_back(Person("猴子", 8));
	v.push_back(Person("大爷", 32));

	replace_if(v.begin(), v.end(),commend(), Person("SB", 999));

	for_each(v.begin(), v.end(), myprintf);

}

int main()
{
	test01();

	system("pause");
	return 0;
}