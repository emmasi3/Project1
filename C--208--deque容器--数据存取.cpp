#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	//1.访问数据的两种方式  [] 重载运算符， at() 内置函数

	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << "  ";
	}
	cout << endl;

	//2.
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << "  ";
	}
	cout << endl;
	//3.输出 首位或者末尾的元素
	cout << d.front() << "  " << d.back() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}