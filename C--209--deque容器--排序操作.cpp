#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	deque<int>d;
	for (int i = 10; i>-1; i--)
	{
		d.push_back(i);
		cout << d[10-i] << "  ";
	}
	cout << endl;
	
	// 利用 sort() 标准库函数 排序
	sort(d.begin(), d.end());
	/*sort(d[0], d[d.size()-1]); */      //-- 如果是 deque 或者其他容器 ,需要一个“区间”,必须由“迭代器（指针）”来操作
	for (int i = 0; i < d.size(); i++)   //-- 若是普通的区间，那完了，报错，因为 sort() 没有那种“重载函数”
	{
		cout << d[i] << "  ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}