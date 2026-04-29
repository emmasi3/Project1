#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//谓词（概念）：返回值为 bool 类型的仿函数
//一元谓词：只有一个参数
//二元谓词：2个参数

class f
{
public:
	bool operator()(int a)//此为“一元谓词”
	{
		return a > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), f());//2. find_if（标准库函数），
	cout << *it << endl;                //需要三个参数，前两个为“左闭右开”的迭代器区间，后一个为 Pred “谓词”***
	if (it != v.end())                   //它的返回值类型 为“迭代器”
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}