#include <iostream>
using namespace std;
#include <string>

class Building;
class Friendd
{
public:
	Friendd()
	{
		this->name = "张三";
	}

	void visit(const Building& p);
public:
	string name;
};



class Building
{
	friend void Friendd::visit(const Building& p);
	// 1. 这里是 成员函数作友元的声明，和其他两个一样，
	// 但是，如果不加 Friend:: 作用域下的，就会被当作 -- 全局函数，而这里要的是成员函数
	// 
	// 2. 成员函数作友元的--声明，前面必须有 该类的完成定义，只有 声明 class Friendd; 依旧会报错 --- 未定义类型
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


void Friendd::visit(const Building& p)
{
	cout << this->name << "正在访问：" << p.LivingRoom << endl;
	cout << this->name << "正在访问：" << p.BedRoom << endl;
}
// 3. 最恶心的一点，成员函数的声明-- 你就放在所有类之后，因为，这他奶奶的，太容易出错了，而且有的错，你不改成员函数主体
//    的位置，根本行不通，而且是逻辑上的死循环错误--- 把哪个放前面都不对，
//
// 4. 所以，so》》对于所有“成员函数”，“类内声明，所有类之外定义”，不然，等着慢慢改吧你
// ！！！！！！！！

void test01()
{
	Building b1;
	Friendd f1;
	f1.visit(b1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}