#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;
	for (int i = 0; i < 10; i++)
	{
		L.push_back(i);
	}
	list<int>::iterator it = L.begin();
	//1. L[]     报错
	//2. L.at()  报错
	//3. it=it+1;报错
	//原因：list 容器的底层是链表结构，并不是“连续的线性”空间，所以无法实现将 地址+1，就能访问到数据的情况，不连续，
	//      it=it+1 报错，list 的迭代器是 “双向迭代器”，不支持随机式访问

	cout << L.front() << "  "<< L.back() << endl;
	//4.但是它提供 末尾和头部 数据的访问
}

int main()
{
	test01();

	system("pause");
	return 0;
}