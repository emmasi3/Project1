#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(int v)
{
	cout << v << " ";
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(80);
	v.push_back(100);
	v.push_back(20);
	v.push_back(70);

	//1.格式
	//2.作用：会将区间内的所有值 替换为 想要的，是“所有，不是一个20，是所有的20”
	replace(v.begin(), v.end(), 20, 999);

	for_each(v.begin(), v.end(), myprintf);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}