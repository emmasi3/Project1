#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

bool mycompare(int v1, int v2)
{
	return v1 > v2;
}

void test01()
{
	list<int>L;
	for (int i = 0; i < 11; i++)
	{
		L.push_back(i);
	}
	myprintf(L);

	L.reverse();//当然  reverse(反转) != reserve(保留)
	myprintf(L);//1.将数据域按“反着”的顺序排列

	//  sort(L.begin(), L.end());   2.这句代码会报错，为什么？原因：list 的迭代器是“双向迭代器”，STL标准库中的所有函数
	//                               .只支持拥有随机访问迭代器的容器使用 ！！！！
    //  3.但是不支持使用全局标准函数库的容器，内部也有内置函数可以使用，因为那是专门的 ！！！！
	L.sort();
	myprintf(L);

	//4.默认只支持从小到大排序，但是这样可以按照自定义方式排序
	L.sort(mycompare);   //这里需要传入一个返回值类型为 bool 的自定义函数，就像 for_each() 函数一样，内部会执行
	myprintf(L);         //传进去的函数：compare(),然后执行相应的操作，至于到底为什么这么写？不知道，1865行代码，慢慢看！
}

int main()
{
	test01();

	system("pause");
	return 0;
}