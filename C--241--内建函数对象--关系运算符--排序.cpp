#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(99);

	//1.倒序
	sort(v.begin(), v.end(), greater<int>());//一般需要传入“谓词”-- 自己写的仿函数，但是人家提供了这套算法，现成的
	                                    // gearter<double>() 也行，这样也可以排序
	                                    // sort（）函数，之所以默认排序为 小 --> 大，是因为：内部有一个 less<>() 仿函数
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}