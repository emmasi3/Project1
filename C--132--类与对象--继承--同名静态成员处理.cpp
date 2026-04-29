#include <iostream>
using namespace std;

class base
{
public:
	static int a;
	static void f()
	{
		cout << "base--静态调用" << endl;
	}
};
int base::a = 10;


class son:public base
{
public:
	static int a;
	static void f()
	{
		cout << "son--静态调用" << endl;
	}
}; int son::a = 10;


void test01()
{
	//1. 通过对象调用同名成员
	// . 这和前几节课一样，都是通过作用域调用的

	//2. 通过“类名”调用同名成员 -- 这是静态成员独有的特点--因为：它在执行主函数区域代码时，就已经分配好了捏
	// . 而且，它不像其他成员一样，需要创建 类对象，也就是实例化对象之后，才会给成员“分配内存”
	// . 所以其他成员不能利用“类名”来访问，因为访问的空间“还没有被分配”，
	// . 但是，静态成员，直接被 “刻”在了类上，是类本身具有的，就像类名
	son::f();
	son::base::f();
	//3. 第一个 :: 作用-- 我要通过类名的方式访问一个数据-- 那个数据就是 base 作用域下面的 f() 函数 ！！！！
	// . 这是重要的解读！！！

}

int main()
{
	test01();

	system("pause");
	return 0;
}