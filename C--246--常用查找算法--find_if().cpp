#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class rule
{
public:
	bool operator()(int v)
	{
		return v % 2 == 0;
	}
};

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

class RULE
{
public:
	bool operator()(const Person& p)
	{
		if (p.name == "B")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test01()
{
	//1.内置数据类型
	vector<int>v;
	v.push_back(9);
	v.push_back(2);
	v.push_back(6);
	v.push_back(4);
	v.push_back(16);
	v.push_back(13);

	vector<int>::iterator vt = find_if(v.begin(), v.end(), rule());
	cout << *vt << endl;
	cout << "---------------" << endl;

	//1.1显示所有的符合要求的值
	vector<int>::iterator vtt = v.begin();
	for ( vtt = find_if(vtt, v.end(), rule()) ; vtt != v.end(); vtt = find_if(vtt+1, v.end(), rule()))
	{
		cout << *vtt << "  ";
	}
	cout << endl;
	//这是利用“迭代器”以及“find_if() 函数”
	//但是，这本来是一件非常简单的事情，为什么会这么复杂，直接用 v[] 遍历然后再if（）就好了，哎！
	//可能是遇到复杂问题的时候，这是最好用的吧······

	//2.自定义数据类型
	vector<Person>v2;
	//放数据
	string name = "ABCDE";
	int age = 0;
	string m_name;
	for (int i = 0; i < 5; i++)
	{
		m_name.append(name, i, 1); //这两行写了不止一遍了，好好复习一下！！！
		age = rand() % 8 + 18;

		v2.push_back(Person(m_name, age));
		m_name = "";
	}

	vector<Person>::iterator v2t = find_if(v2.begin(), v2.end(), RULE());
	cout << v2t->name << "  " << v2t->age << endl;

	//3.这里的标准函数参数 无非就三种--- 仿函数、谓词、value

}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	system("pause");
	return 0;
}