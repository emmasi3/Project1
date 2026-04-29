#include <iostream>
using namespace std;
#include <string>

class Building
{
	friend void test01(Building& p1);// 类内声明

public:
	Building()
	{
		this->LivingRoom = "客厅";
		this->BedRoom = "卧室";
	}

public:
	string LivingRoom;
private:
	string BedRoom;

};

//10.对于 test01() 函数的修改是我在学习数据结构，栈的实现时做的，若想要在友元函数内部调用，类对象的私有属性，光有友元声明
//  .子啊现在看来，很显然是不够的，你要保证 p1 是在 test01() 这个块内的，而现在只是通过它的地址 &p1 来调用在堆区的 p1
//  .实际上 p1.LivingRoom 就是在堆区进行这个操作，而不是在友元函数中进行，所以无法访问 -- 
//  .     要保证是在友元函数内部调用私有属性

void test01(Building& p1)// 全局函数
{
	//Building p1;
	cout << p1.LivingRoom << endl;
	// 1. 那么在类外，不能调用 private 里的东西
	//  . 这时候，只需要让 test01() 作为类 Building 的朋友--友元，就可以访问私有内容了，只需要在类内，做声明 + friend
	cout << p1.BedRoom << endl;

	// 友元function作用： 用来调用 private 内的属性或者东西
}

int main()
{

	Building p1;
	test01(p1);

	system("pause");
	return 0;
}