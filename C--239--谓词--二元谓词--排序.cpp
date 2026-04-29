#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class compare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}

	v.resize(10);

	vector<int>(v).swap(v);//1.用来清理多余的空间，v 所占用的内存过大

	cout << v.capacity() << endl;

	//2.倒序--二元谓词
	sort(v.begin(), v.end(), compare());//2.此处，是“匿名对象”-- 用默认--无参--构造函数创建

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