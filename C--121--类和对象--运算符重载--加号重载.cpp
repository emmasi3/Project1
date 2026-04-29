#include <iostream>
using namespace std;

class NUM
{
public:
	NUM()
	{
		this->a = 10;
		this->b = 20;
	}
public:
	void operator+(const NUM& p);
public:
	int a;
	int b;
};

/*void NUM::operator+(const NUM& p)
{
	this->a += p.a;
	this->b += p.b;
}


void test01()
{
	NUM a;
	NUM b;
	a.operator+(b);

	// 1. 利用成员函数作运算符重载
	// 
	//  . 这是正常的加减，但是如果我非要形式上是 a+b ,我还想要对 a 属性处理后得到相同的结果，该如何？
	//  . 只需要用特殊字符--- operator+    来作为函数的名字，便可以直接用 a+b,,得到自己想要的结果了！！！

	cout << a.a << "  " << a.b << endl;

	a + b;// 这就是例子，实质在上面
	cout << a.a << "  " << a.b << endl;
}*/

void operator+(NUM &p1,NUM &p2)
{

	p1.a += p2.a;
	p1.b += p2.b;
	cout << p1.a << "  " << p1.b << endl;
}



int main()
{
	NUM p1;
	NUM p2;
	operator+(p1,p2);// 这是实质
	// 2. 也可以是“全局函数”作用算符重载
	//  . 还可以
	p1 + p2;

	// 3. 运算符重载的专用 函数名 operator+ 也可以发生重载
	//  . 即：形参的顺序，类型，个数 改变，都可以满足重载条件


	system("pause");
	return 0;
}