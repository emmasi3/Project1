#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << "\t" << (*it).second << endl;
	}
}

void test01()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	myprintf(m);

	//1.查找-- find() 内置函数
	map<int, int>::iterator pos = m.find(2);  // 和set 容器一样，返回值类型 -- “迭代器”
 	cout << pos->first << "\t" << pos->second << endl;//若没有查到，则返回  m.end()
	
	//2.统计 -- count()  
	int num = m.count(1);  //返回值只有 0,1 因为 参数具有唯一性，搜索的是索引的数量，自然只有1,0
	cout << num << endl;   //但是，multimap 可以允许多个相同的 key 存在，count() 的返回值可能更多！！！

	multimap<int, int>mm;
	mm.insert(make_pair(1, 10));
	mm.insert(make_pair(1, 20));
	mm.insert(make_pair(1, 30));

}

int main()
{
	test01();

	system("pause");
	return 0;
}