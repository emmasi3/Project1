#include <iostream>
using namespace std;

// 1. 问题：对 （） 进行重载，并且具有，加和打印结果的功能

class NUM
{
public:
	void operator()(NUM &p2) // 1. 但凡有 operator() 函数名的函数，统称为---“仿函数”
	{
		int sum = this->num + p2.num;
		cout << sum << endl;
	}
public:
	NUM(int a)
	{
		this->num = a;
	}
private:
	int num;
};

void test01()
{
	NUM p1(50);
	NUM p2(60);
	p1.operator()(p2);
	p1(p2);
	// 1. 这是对 （） 函数调用符的重载

	NUM(10)(p2);

	// 2. 还可以用 匿名对象调用函数 ，因为 NUM(10) 是一个匿名对象，（p2）则是调用“重载函数”
}

int main()
{
	test01();

	system("pause");
	return 0;
}