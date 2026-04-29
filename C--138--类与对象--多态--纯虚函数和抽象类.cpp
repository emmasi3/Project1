#include <iostream>
using namespace std;

class base
{
public:
	virtual void func() = 0; //1. 此为“纯虚函数”，特点：不能实例化对象，，，该类成为：抽象类
};

class son :public base
{
public:
	virtual void func() //2. 没有“重写”这一步，子类也会成为：抽象类，不能实例化对象
	{
		cout << "开心超人" << endl;//3. 重写 ：函数名，返回值类型，形参列表相同即可
	}

};

void test01()
{
	base& p1 = *new son;
	base* p2 = new son;
	p1.func();
	p2->func();
	delete &p1;
	delete p2;
}

int main()
{
	test01();

	system("pause");
	return 0;
}