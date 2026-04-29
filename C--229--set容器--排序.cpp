#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class mycompare    //定义一个类，存放仿函数的类
{
public:
	bool operator()(int v1, int v2)const//这是仿函数，就和 list 容器里面一样，自定义排序规则，只不过这个需要重载 () 运算符
	{
		return v1 > v2;
	}
};

void myprintf(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	myprintf(s1);
	//1. 反着排序
	set<int,mycompare>s2;

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);

	for (set<int, mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	//步骤：1.在set 模版参数列表中添加  “类名”-- 存放“仿函数”的类名 set<int,mycompare>s2;这样实例化的 s2 就可以按照
	//       .仿函数中写的规则进行排序了
	//      2.参上
	//      3.重载运算符仿函数 bool operator()()const{};   在vs中，这个const 是必不可少的，否则编译通过不了
}

int main()
{
	test01();

	system("pause");
	return 0;
}