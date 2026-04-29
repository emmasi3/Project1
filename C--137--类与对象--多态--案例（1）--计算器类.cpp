#include <iostream>
using namespace std;

class calculate
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int a;
	int b;
};
//1. 加法
class addcalculate:public calculate
{
public:
	int getresult()
	{
		return a + b;
	}
public:
	addcalculate(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	int a;
	int b;
};
//2.乘法
class mul:public calculate
{
public:
	int getresult()
	{
		return a*b;
	}
public:
	mul(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	int a;
	int b;
};

// 3. 动态多态：优点：
// 便于后续的维护和修改（相对于if，else语句写的普通代码而言，确实方便了很多）
// 结构可读性增加      （大概是能更容易让别人读得懂吧）
// 代码组织结构清晰


// 4. 要记得：动态多态的三大条件：   有继承，有重写（virtual)，用父类的指针或引用指向子类
void test01(calculate *alg)
{
	cout << alg->getresult() << endl;
}

void test02()
{
	calculate* abc = new mul(40,80);// 5.动态多态的第三个条件也可以这样，直接 new mul; 这里+ （40，80）是因为：
	delete abc;                        //在mul中，我只定义了 有参--构造函数，没有无参--构造函数，所有得带入参数

}             

int main()
{
	addcalculate A(40,80);
	test01(&A);

	mul M(40, 12);
	test01(&M);


	system("pause");
	return 0;
}