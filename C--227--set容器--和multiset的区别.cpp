#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//1.set 容器插入数据时会返回检测值————是否重复，类型为 pair
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10);//insert()内置函数会返回一个 pair<iterator,bool> 的值，可以这样接收
	if (ret.second)                 //这里的 ret.second 可以调用 bool 这个成员变量，所以 pair 实际上是一个“类模版”
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}

	//2.但是 multiset 容器的 insert 却不会，因为：
	// .他可以接受多个 10 的相同数据
}

int main()
{
	test01();

	system("pause");
	return 0;
}