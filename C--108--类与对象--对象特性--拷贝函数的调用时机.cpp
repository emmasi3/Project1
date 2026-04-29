#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默认--构造函数的调用" << endl;
	}
	Person(int a) 
	{
		cout << "有参--普通--构造函数的调用" << endl;
	}
	Person(const Person &p)
	{
		age = p.age;   // 这一行是“拷贝”的基本用法

		cout << "有参--拷贝--构造函数的调用" << endl;
	}

	~Person()
	{
		cout << "析构函数的调用" << endl;
	}

	int age;
};

void test01()
{
	//1. 使用一个已经创建完毕的对象来初始化一个新对象
	Person p1(10); // 这是已经创建的对象
	Person p2(p1); // 这是利用创建好的 p1 来创建的 p2新对象，而且是--拷贝函数调用类的
}

void test02()
{
	//2. 值传递 给函数参数传值
	Person p1; // 创建了一个 p1 对象， p1 也是一个“值”	
	dowork(p1);// “值传递”的本质--- 拷贝一份一模一样的对象，（但是，地址不一样）

	           // . 调用 dowork(p1) ；传值时， Person p = p1 ;;眼熟吗？这是“隐式转换法”，就是 Person p = Person(p1)
	           // . 这将会调用“拷贝构造函数”！！！  
	//重在理解
}
void dowork(Person p)
{

}


void test03()
{
	//3. 值传递，返回局部对象
	Person p1 = dowork02();
	// 这里相当于 == Person p1 = p2 ;也是一个拷贝构造函数的调用

}
Person dowork02()
{
	Person p2;//这里的 p2在dowork02() 执行完毕后，会被释放，不能用“指针”或者“引用”来传递
	return p2;//. 可以用“值”传递，因为在dowork() 执行完毕前，会复制一份 p2 来传递，也就是
	          // . 返回了“局部对象”-- p2
}





int main()
{
	test01();
	test02();
	test03();
	


	system("pause");
	return 0;
}