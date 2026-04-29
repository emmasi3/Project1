#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(int v)
{
	cout << v << "  ";
}

class myprint
{
public:
	void operator()(int v)
	{
		cout << v << "  ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//1.传入 “全局函数”操作
	for_each(v.begin(), v.end(), myprintf);
	cout << endl;

	//2.传入 “仿函数” 操作
	for_each(v.begin(), v.end(), myprint());//仿函数 内部一定是有一个 operator() 重载 () 运算符的操作，否则就不是仿函数！
	cout << endl;

	//3. 你如果在仿函数 myprint 中，void myprintf(int v)； 然后还想正确执行代码，是不可能的，因为：
// . for_each() 函数内部，会在遍历某一个值的时候，将“值”返回给你穿进去的函数 myprintf(),当你传入的是 函数对象myprint()
	// .的时候，它会直接 myprintf() 在内部将这个当成函数来用，() 此时是一个重载运算符，所以在内部调用时，就等于执行
	// .operator()() 函数，所以，要注意 for_each() 的底层实现！！！

}

int main()
{
	test01();

	system("pause");
	return 0;
}