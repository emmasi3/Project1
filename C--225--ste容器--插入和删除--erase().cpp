#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
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
	//1.指定迭代器删除
	s1.erase(s1.begin());
	myprintf(s1);
	//2.传入数据（查找）删除
	s1.erase(40);//因为：set 容器里面的元素有唯一性，所以可以指定元素删除
	myprintf(s1);
	//3.指定区间删除，这个合格vector 一样

}

int main()
{
	test01();

	system("pause");
	return 0;
}