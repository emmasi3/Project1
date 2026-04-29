#include <iostream>
using namespace std;
#include <string>

class Building
{
	friend class GoodGay;// 2. 这是 GoodGay  类作 Building 的友元 ，也就是利用 GoodGay 里面的成员函数不仅可以访问
	                     // . Building 中的公开属性，也可以访问，私有属性
public:
	Building();//1. 类内做声明
public:
	string LivingRoom;
private:
	string BedRoom;
};
Building::Building()
{
	this->LivingRoom = "客厅";
	this->BedRoom = "卧室";
}// . 类外做定义，不仅仅对于静态成员变量，对于成员函数也可以这样做，只需要注意加上作用域就好

// 3. 第三点，也是最重要的一点，如果你把 GoodGay 放在了 Building 上面，那么你在，GoodGay 里面写的所有的关于 Building 
//  . 的东西，都无法识别，也就是没有定义，因为：编译器，还没有到那一块，绝对会报错，所以，要注意顺序！！！
//  . 当然，friend class GoodGay; 这句相当于声明-- 有这个 GoodGay 类的存在-- GoodGay 是他的友元，所以，这里顺序不影响！！
// 
//  . 这里我要强调一下，之所以在没有GoodGay 完整主体在前的情况下，还是能够声明友元，是因为：：这句代码，没有调用 GoodGay 
//  . 内部的成员，一旦涉及，抱歉，会报错
class GoodGay
{
	
public:
	GoodGay()
	{
		this->name = "好基友";
	}
	void visit(const Building &p)
	{
		cout << this->name << "正在访问你的：" << p.LivingRoom << endl;
		cout << this->name << "正在访问你的：" << p.BedRoom << endl;
	}
public:
	string name;
};

void test01()
{
	Building b1;
	GoodGay g1;
	g1.visit(b1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}