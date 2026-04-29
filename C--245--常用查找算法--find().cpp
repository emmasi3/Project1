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
	//
	bool operator==(Person p)
	{
		if (this->name == p.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string name;
	int age;
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(),v.end(), 5);
	if (it != v.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	//2.查找自定义数据类型
	vector<Person>vv;

	string name = "ABCDE";
	int age = 0;
	string m_name;
	for (int i = 0; i < 5; i++)
	{
		m_name.append(name, i, 1); //这两行写了不止一遍了，好好复习一下！！！
		age = rand() % 8 + 18;

		vv.push_back(Person(m_name,age));
		m_name = "";
	}
	/////////////////////////////////////////
	Person p("A", 18);

	vector<Person>::iterator itt = find(vv.begin(), vv.end(), p);//这里的底层实现判断是否相等时，会
	if (itt != vv.end())                                 // p == v[],所以，只需要重载运算符，那么会自动调用 p 的比较规则
	{                                                   //此为自定义数据类型的比较方式
		cout << "找到了：" << itt->name <<"  " << itt->age << endl;
	}
	else
	{
		cout << "没找着" << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	system("pause");
	return 0;
}