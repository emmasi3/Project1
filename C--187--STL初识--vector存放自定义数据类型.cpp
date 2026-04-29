#include <vector>
#include <algorithm>
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

void myprintf(Person* it)
{
	cout << (*it).name << "\t" << (*it).age << endl;
}

void test01()
{
	vector<Person>v;

	Person p1("张三", 18);
	Person p2("李四", 19);
	Person p3("王五", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//1.遍历 容器（存放类）
	//(1)第一种  it 理解为指针，所以 * 解引用之后，表示的是 Person 类型的数据，也就是容器 v 中放置的 p1,
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).name << "\t" << (*it).age << endl;
	}
	//(2)第二种，it 既然是指针，那就可以 -> 来调用指向对象的一些特性，比如：成员变量，成员函数
	cout << endl;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->name << "\t" << it->age << endl;
	}
	cout << endl;
	//2.存放自定义“指针”类型数据
	vector<Person*>w;

	Person p11("张三", 18);
	Person p22("李四", 19);
	Person p33("王五", 20);

	w.push_back(&p1);
	w.push_back(&p2);
	w.push_back(&p3);

	for (vector<Person*>::iterator it = w.begin(); it != w.end(); it++)
	{
		cout << (*it)->name << "\t" << (*it)->age << endl;
	}
	//利用内置函数遍历
	cout << endl;
	for_each(w.begin(), w.end(), myprintf);//时刻记住，这个函数是在底层会被调用，而且会自动传入参数----就是数组vector
	                                       //中的每一个元素，传入的是“值”在本例中是--地址--只想指针的地址
}

int main()
{
	test01();

	system("pause");
	return 0;
}