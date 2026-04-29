#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const set<int>& S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	s1.insert(10);   //1. set 容器没有 push_back() 的内置函数，只有 insert() 函数
	s1.insert(20);   //2. set 容器对插入的所有数据都会“自动排序”
	s1.insert(30);   //3. set 容器不允许插入重复的数据，如：30 不会被插入
	s1.insert(40);   //4. set 容器的底层使用 “二叉树” 实现的，这决定了第2,3点
	s1.insert(30);

	myprintf(s1);//5.set 容器的其余操作，基本和vector 一致
}                //6.set 容器不支持 resize() 重新指定大小，但是可以“查看大小” S1.size();

int main()
{
	test01();

	system("pause");
	return 0;
}