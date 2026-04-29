#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name,int age,int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}

	string name;
	int age;
	int height;

};

void myprintf(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << (*it).name << "\t" << (*it).age << "\t" << (*it).height << endl;
	}
}

bool mycompare(Person& p1, Person& p2)   //翻译条件：：先按照年龄从小到大排，若年龄相同，则比较身高，从大到小排
{                                        //往后的比较规则也是这样的，所以只需要不断加入选择语句就好了！！！
	if (p1.age == p2.age)
	{
		return p1.height > p2.height;
	}
	else
	{
		return p1.age < p2.age;
	}
}

void test01()
{
	list<Person>L;

	Person p1("张三", 18, 180);
	Person p2("李四", 25, 165);
	Person p3("王五", 25, 180);
	Person p4("赵六", 19, 200);
	Person p5("傻逼", 25, 250);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout << "排序前：" << endl;
	myprintf(L);
	
	cout << "-------------------" << endl;
	//1.排序自定义数据类型 -- 自己制定排序规则
	L.sort(mycompare);
	myprintf(L);
}

int main()
{
	test01();

	system("pause");
	return 0;
}