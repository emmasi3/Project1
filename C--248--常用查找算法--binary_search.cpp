#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//1. binary_search() ---- 二分查找
// . 效率很高，其实就是 2 分法找数据，循环次数 是次方级别的，所以比一个一个查快很多，时间缩短了 次方倍
// 
//2.但是要求所查找区间 是一个 “有序（正序）容器”（这和内部实现有关）

void test01()
{
	//正序
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "存在" << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}

	v.clear();
	//倒序
	for (int i = 9; i > -1; i--)
	{
		v.push_back(i);
	}
	bool rett = binary_search(v.begin(), v.end(), 0);
	if (rett)
	{
		cout << "存在" << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}
	//倒序是不行的，只有“从小到大”排序才可以
}

int main()
{
	test01();

	system("pause");
	return 0;
}