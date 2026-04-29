#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//1.利用“[]重载运算符”访问
	string s1 = "hello";
	cout << s1[1] << endl;

	//2.利用成员函数 at() 访问
	cout << s1.at(2) << endl;

	//3.利用两种方式改变
	s1[1] = 'B';
	s1.at(0) = 'A';
	cout << s1 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}