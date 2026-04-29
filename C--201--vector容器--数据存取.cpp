#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
    //1.访问存进去的数据
	  //(1) [] 重载运算符
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;
	  //(2) at() 内置函数
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << "  ";
	}
	cout << endl;

	//2.访问最后/第一个元素

	cout << v.front() << "  " << v.back() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}