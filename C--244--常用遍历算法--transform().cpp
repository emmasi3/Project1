#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(int v)
{
	cout << v << "  ";
}

class f
{
public:
	int operator()(int v)
	{
		return v + 100;
	}
};

int ff(int v)
{
	return v + 100;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;

	v2.resize(v1.size()); //3.使用 transform （）之前，必须给 v2 分配适合的大小，否则不能正确执行，因为：没空间放数据

	transform(v1.begin(), v1.end(), v2.begin(), f());


	//1.transform（）函数只是做了一个拷贝构造类似的功能，附加 f() 函数的操作，但是原来的 v1 容器并没有被改变
	for_each(v1.begin(), v1.end(), myprintf);
	cout << endl;

	for_each(v2.begin(), v2.end(), myprintf);
	cout << endl;
	//2.体会 f() 的功能和写法！！  仿函数 -- 必须有 （） 运算符重载，否则不能运行！！！
	vector<int>v3;

	v3.resize(v1.size());

	transform(v1.begin(), v1.end(), v3.begin(), ff);

	for_each(v3.begin(), v3.end(), myprintf);
	cout << endl;

	//4.和 for_each（）一样，最后一个参数，可以是“仿函数”也可以是“全局函数”
}

int main()
{
	test01();

	system("pause");
	return 0;
}