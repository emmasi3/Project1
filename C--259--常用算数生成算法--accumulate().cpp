#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int>v;
	for (int i = 0; i < 101; i++)
	{
		v.push_back(i);
	}

	//1.求和，一般想到的是 for() 循环吧！，但是那样还要自己写（虽然好像并不复杂？）
	int total = accumulate(v.begin(), v.end(), 0);
	cout << total << endl;

	int total_ = accumulate(v.begin(), v.end(), 1000);
	cout << total_ << endl;
	//2.注意格式， 最后一位  1000,0  是定义的累加起点 ！！！
	//3.返回值类型是 int 类型
}

int main()
{
	test01();

	system("pause");
	return 0;
}