#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(int v)
{
	cout << v << " ";
}

void test01()
{
	// merge() 算法
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)//3. 需要合并的两个序列（要求）：(1) 都必须为“有序序列”；(2)顺序（大->小）、（小->大）
	{                           // .                                                          必须要一致
		v1.push_back(i);
		v2.push_back(i * 10);
	}

	vector<int>vv;
	vv.resize(v1.size() + v2.size());//1. 合并成一个新容器 vv ,需要“提前”指定大小，否则报错

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vv.begin());//2. 格式

	for_each(vv.begin(), vv.end(), myprintf);//5.重新合并的 容器 vv 依旧是一个“有序序列”
	cout << endl;
}
int main()
{
	test01();

	system("pause");
	return 0;
}