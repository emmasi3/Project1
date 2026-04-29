#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//1.“ 搬运 v1 容器到 v2 容器，并且顺便“取反” ”
	vector<bool>v2;
	v2.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	//至于这里为什么要用 “逻辑非仿函数”，大概是因为： v1,v2 是用来存放 bool 类型数据的容器，非 刚好就等于“取反”
	//这里的 “逻辑仿函数”基本没什么用武之地，实际开发中更是一点都用不上！！！了解即可
}

int main()
{
	test01();

	system("pause");
	return 0;
}