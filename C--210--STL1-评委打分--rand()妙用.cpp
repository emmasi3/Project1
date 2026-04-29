#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name)
	{
		this->name = name;
	}

	void f()
	{
		this->average = this->score / 8.0;
	}
	string name;
	double average=0;
	int score = 0;
};

void f(Person& p)
{
	vector<int>v;               //这里的分数本来可以用 deque 容器来储存的，但是我写烦了，所以直接用vector 来代替，
	for (int i = 0; i < 10; i++)//用 deque 的优点：可以对“头部和尾部”更好做处理
	{
		v.push_back(rand() % 41+60);  //***这一行是关键 ！！！要注意我的写法 现在的范围 [60,100]!!! 
	}
	sort(v.begin(), v.end());

	v.erase(v.begin());
	v.erase(v.end() - 1);

	for (int i = 0; i < v.size(); i++)
	{
		p.score += v[i];
	}
	p.f();//计算平均成绩
}

void test01()
{
	vector<Person*>v;
	//
	Person p1("张三");
	Person p2("李四");
	Person p3("王五"); 
	Person p4("赵六");
	Person p5("傻狍");
	//
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	//
	f(p1); f(p2); f(p3); f(p4); f(p5);
	for (int i = 0; i < 5; i++)
	{
		cout << (*v[i]).name << "  " << (*v[i]).average << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));//1. 随机数种子，想学自己去查，但是没有这句话，你的 rand() 随即出来的数字，都是
	                                // . 固定的，无参考意义

	test01();

	system("pause");
	return 0;
}