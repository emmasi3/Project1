#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	//1. adjacent() 函数返回第一个 “相邻”&&“重复”元素的迭代器，缺一不可，若无，返回 v.end()
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	int a = *it;
	for (it; *it == a; it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}// 2.网课上说，会考！！！面试会考！！！

int main()
{
	test01();

	system("pause");
	return 0;
}