#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//1. compare()
	string s1 = "hello";
	string s2 = "hello";
	int a = s1.compare(s2);
	if (a == 0)
	{
		cout << "s1 == s2" << endl;
	}
	cout << a << endl;

	if (s1 == s2)
	{
		cout << "s1 == s2" << endl;
	}

	//compare() 的返回值类型为 int ，且只会返回 1,0,-1  分别表示" > < == "
}

int main()
{
	test01();

	system("pause");
	return 0;
}