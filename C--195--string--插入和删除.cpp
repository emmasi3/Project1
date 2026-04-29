#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	string s1 = "hello,world";
	//1.插入-- insert()
	s1.insert(1, "SBSB");//注意：结果不是 heSBSBllo,而是 hSBSBello,因为：要保证插入的字符串的下标是从 “1” 开始的
	cout << s1 << endl;
	//2.删除-- erase()
	s1.erase(1, 4);    //删除从 1 下标开始的 4个 的字符！--前面是下标，后面是“字符数”
	cout << s1 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}