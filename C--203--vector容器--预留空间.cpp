#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int>v;

	v.reserve(100000);

	//1.查看存放100000个数据，到底“动态扩展”了多少次内存？
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
		//解释：每一次“动态扩展”都是会改变整个容器所在的“地址”，所以只需要用“指针 p ”标记初识的位置，然后判断
		//这个保存的地址，是否和容器所在的首地址相同，即可！
		//如若相同，则证明没有“动态扩展”
		//如若不相同，则证明“动态扩展”了一次
	}
	cout << num << endl;

	//2.动态扩展了 30 次，显然是非常繁琐的，怎样才能减少这个次数呢？
	//提前给 v 分配较大的空间 或者 合适的空间 ！！！ -- reserve()
}

int main()
{
	test01();

	system("pause");
	return 0;
}