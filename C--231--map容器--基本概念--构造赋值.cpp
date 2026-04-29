#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	//map 容器基本概念：
	//1.map 中所有元素都是  “对组”-- pair
	// .这也就意味着 insert() 内置函数参数只能填写，对组pair
	// 
	//2.pair 中第一个元素为 key(键值)--索引，后期可以通过这个访问value
	//3.pair 中第二个元素为 value(值)--真实值的储存空间，可以通过 key 访问
	//4.map 容器的底层实现，-- 二叉树，所以具有 set/multimap 的基本性质 -- 对于传进来的数据“自动排序”（根据键值key）
	//5.map 容器 -- 关联式容器--大概是因为：二叉树，且元素都是“对组”
	//6.map / multimap 的区别：和 set / multiset 的区别大差不差，都是允不允许重复的问题
	// .但是区别是：  set 不允许“值”重复，因为：它里面就一个元素，且没有嵌套元素
	// .              map 不允许“键值 key ”重复 ,而对于 value 则不做要求，大概是因为：key 是索引，索引都重复了，
	// .              还怎么查数据？

	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << (*it).first << "\t" << (*it).second << endl;
	}
	cout << m1[1] << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}