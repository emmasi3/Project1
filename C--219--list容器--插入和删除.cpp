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
	L.insert(L.end(), 3, 5);
	myprintf(L);

	//1.其余的内置函数都和 vector 差不多，看那个

	//2. remove() -- 实用的函数
	L.remove(5);
	myprintf(L); //这个内置函数（成员函数）会自动将“所有数据域” == 5 的“结点”删除，并且按顺序“链接”剩下的结点
}

int main()
{
	test01();

	system("pause");
	return 0;
}