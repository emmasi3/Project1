#include <iostream>
using namespace std;

class dad
{
public:
	int a = 10;
protected:
	int b = 20;
private:
	int c = 30;
};

// 1. 公共继承--- 子类继承的同时，将公共成员 及“以下”特权，都改为--公共
class son1 :public dad
{
public:
	void f()
	{
		a = 10;   // 子类中--public
		b = 20;  // 本就是 protected
	//	c = 30;    父类中的私有权限--子类中依旧为私有成员，不能访问
	}
};

void test01()
{
	son1 s1;
	s1.a;
//	s1.b;  b ,c 都是类内可以访问，类外不可以
}


// 2. 保护继承-- 子类继承时，将保护成员及“以下”，都改为--保护
class son2 :protected dad
{
public:
	void f()
	{
		a = 10;// -->保护  --- 类外都不能访问
		b = 20;// --保护
	//	c = 30;   本就是 私有（父类的）
	}
};

class son3 :private dad
{
	void f()
	{
		a = 10;// -->私有
		b = 20;// -->私有
	//	c = 30;  本就是 私有
	}
};

 // 1. 保护成员--- 父类，子类都可以访问
//  2. 私有成员--- 父类可以访问，子类不能（即使已经继承）

int main()
{


	system("pause");
	return 0;
}