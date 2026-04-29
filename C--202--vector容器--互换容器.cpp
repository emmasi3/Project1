#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	//1.swap() 内置函数（成员函数）交换容器内容
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	for (int i =9;i>-1;i--)
	{
		v2.push_back(i);
	}
	cout << "交换前" << endl;
	myprintf(v1);
	myprintf(v2);
	cout << "交换后" << endl;
	v1.swap(v2);
	myprintf(v1);
	myprintf(v2);
	//2.实际应用--合理删减内存空间--保证不浪费！！！
	vector<int>v;
	for (int i = 0; i < 100000; i++)//当v 的容量太大时
	{
		v.push_back(i);
	}
	cout << "容量" << v.capacity() << endl; //此时容量为 138255
	cout << "大小" << v.size() << endl; //大小为100000

	v.resize(3);
	cout << "容量" << v.capacity() << endl; //此时容量依旧 138255
	cout << "大小" << v.size() << endl;     //大小为         3    ，也就是说，那130000的空间什么都没放，浪费了！
	//所以为了解决这个问题，提出以下办法

	vector<int>(v).swap(v);

	cout << "容量" << v.capacity() << endl; //此时容量为 3
	cout << "大小" << v.size() << endl;     //大小也为为 3

	//解释一下：vector<int>(v)  相当于实例化了一个“匿名对象”，而且使用(v) 的“默认拷贝构造函数”，
	//1.这个会赋值 原来的 v 里面的所有内容，但不包括那 130000个空间，所以现在的 匿名对象-- v' 容量==大小==3
	//2.只需要 swap() 交换这两个容器的所有，就可以产生符合要求，不浪费空间的 v 出现，
	//3.“匿名对象”在执行完这一行代码后，会“自动释放内存”，所以不需要人为控制，而且还达到了目的

}

int main()
{
	test01();

	system("pause");
	return 0;
}