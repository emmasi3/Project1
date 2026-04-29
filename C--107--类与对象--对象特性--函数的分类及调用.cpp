#include <iostream>
using namespace std;

class Person
{
public:
	//1. 分类--- 无参 / 有参
	// .无参
	Person() {
		cout << "无参构造函数--调用" << endl;
	}
	// . 有参
	//  . 拷贝构造函数 / 普通有参构造函数
	//  . 拷贝
	Person(const Person& p) {
		cout << "有参--拷贝构造函数--调用" << endl;
	}
	//  . 除此以外，皆为“普通”
	Person(int a) {
		cout << "有参--普通构造函数--调用" << endl;
	}

public:

	int a;
};

int main()
{
	Person p3;
	//2. 函数的调用
	//2.1 括号法
	Person p;    //这里为什么不加括号呢？ 因为Person p(); 这和定义一个 p()函数语句一模一样，所以计算机会有歧义
	             //并且，如果直接这样写，计算机会“默认”调用--无参--构造函数

	Person p1(10);//这个是调用 有参--普通
	Person p2(p3);//这个是调用 有参--拷贝
	//这也是我推荐的一种，简洁，明了

	//2.2 显示法
    Person p4;
	Person p5 = Person(10);
	Person p6 = Person(p1);
	Person(10);//这是一个“匿名对象”的创建---特点--刚执行完，就被“释放”

	//2.3 隐式转换法
	Person p7 = 10;
	Person p8 = p1;  //这就相当于 Person p8 = Person(p1)  显示法，在计算机“内部”进行

	//所谓的（构造，析构）函数的调用，只不过是，用特殊的方式，指明要调用的 -- “构造”的函数，其实质还是
	// . “创建” /  “销毁”类对象--实例化 的“时候” 选在调用的“函数”


	system("pause");
	return 0;
}