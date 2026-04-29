#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//问题：如果想要通过一个操作块返回"2个"数据时，该怎样做？
	//1.对组 -- pair -- 的创建

	pair<string, int>p1("张三",18);
	cout << p1.first << "  " << p1.second << endl;
	
	//2. 使用 make_pair() 函数创建
	pair<string, int>p2 = make_pair("李四", 15);
	cout << p1.first << "  " << p1.second << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}