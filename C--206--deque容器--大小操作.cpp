#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myprintf(d1);
	//1.  d1.empty()
	//2.  d1.size()  -- 显示“大小”，但是没有 capacity() -- 显示“容量”的操作，因为 deque 的容量理论上接近计算机剩余容量
	//3.  d1.resize(15,1) -- 和 vector 那块的一毛一样！！！
}

int main()
{
	test01();

	system("pause");
	return 0;
}