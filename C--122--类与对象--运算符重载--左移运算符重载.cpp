#include <iostream>
using namespace std;

class NUM
{
	// 1. 问题 cout<< p; 执行完这行代码，直接打印出 p 的所有属性值
public:
	void operator<<(const NUM& p)
	{
		cout << p.a << "  " << p.b << endl;
	}
public:
	int a = 10;
	int b = 20;
};

void test01()
{
	NUM cout;
	NUM p;
	cout << p;
	// 1. 只需要让 cout 出现在 << 的左边就可以了，至于内部的工作，自己写,这是利用成员函数重载 <<
	//  . 但是，这样写的话 不能再追加东西到 p 的后面了，因为，cout 不再是一个命令了，而是一个 NUM 的实例化对象
}

// 2. 利用全局函数
 // . 才可以使用 cout 的“链式输出”，将函数返回值设置为 cout(其类型为 ostream),那么，cout << p == cout，
ostream& operator<<(ostream& cout, NUM& p)
{
	cout << p.a << "  " << p.b << "    ";
	return cout;
}

void test02()
{
	NUM p;
	cout << p << p << endl;
	//  . 并且，如果没有输入 NUM 类型的对象，就会默认执行自带的 cout 功能，也就是不会调用写好的 << 重载程序
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}