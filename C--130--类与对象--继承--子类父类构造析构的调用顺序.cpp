#include <iostream>

class Base
{
public:
	Base(int a, std::string name = "")
	{
		std::cout << "Are you kidding me？" << std::endl;
	}

	virtual void foo() = 0;
};

class A : public Base
{
public:
	//A(int a, std::string name = "")
	//{
	//}

	A(int a, std::string name = "")
		: Base(1,"")
	{
		std::cout << "成功创建 A  && Base！" << std::endl;
	}

	virtual void foo()
	{

	}
};

int main()
{
	A a(1, "");

	return 0;
}
// 1. 有“父类”才有“子类”，--- 构造函数
// 2. 儿“子类”先走          --- 析构函数
/*
* 3、我在“服务器学习syalr”中，ConfigVarBase的构造函数，看见up在函数中执行了一些操作，
*    并且，ConfigVarBase 是一个抽象类，那么在一个不能够实例化对象的抽象类里，它的构造函数
*    如何能够被执行呢？
*    例子：
*    ConfigVar::ptr cv(new ConfigVar(name,description));
*    这行代码在执行的时候，首先会执行 ConfigVar的传参，然后是“初始化列表”
*    {
*		在这中，首先会判断（编译阶段）ConfigVarBase 有没有默认构造函数（和构造函数不一样）
*		1）有默认构造函数：无论你有没有写 :ConfigVarBase() 
*			他都会先执行“父类”的构造函数（这和父类是不是“抽象类”没有一点关系）
*		2）无默认构造函数：你必须在 ConfigVar 的构造函数的“初始化列表”中
*			显式地调用 : ConfigVarBase(name, desc)，否则在编译阶段就会报错，
*			因为如果不调用父类的构造函数，那么 ConfigVarBase 的成员变量就不会被初始化，你让 ConfigVar 怎么用？对吧！
*		具体的例子可以看上面的部分
*    }
* 4、去看类的“默认构造函数”和“构造函数”的区别
* 
* 
*/
