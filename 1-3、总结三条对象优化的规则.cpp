#include <iostream>
#include <memory>

class Test
{
public:
	typedef std::shared_ptr<Test> ptr;

	// 构造函数
	Test(int a = 10) : ma(a) { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
	Test(const Test& t) : ma(t.ma) { std::cout << "Test(const Test&)" << std::endl; }

	// 重载的成员函数 != 构造函数
	// “浅拷贝”
	Test& operator=(const Test& t)
	{
		ma = t.ma;
		std::cout << "operator= " << ma << std::endl;
		return *this;
	}

	int getData() const { return ma; }

private:
	int ma;
};

static Test GetObject(Test t)
{
	int val = t.getData();
	Test tmp(val);
	return tmp;
}

// 9次调用，C++ 14/11 更低标准，可达 11 次(禁止优化的前提下)
static void test1()
{
	Test t1;
	Test t2;
	t2 = GetObject(t1);
}

static Test GetObject2(Test& t)
{
	int val = t.getData();
	// 返回临时对象
	return Test(val);
}

// 经过优化，只有 4 次调用了
static void test2()
{
	Test t1;
	Test t2 = GetObject2(t1);
}

static Test::ptr GetObject3(Test::ptr t)
{
	int val = t->getData();

	return std::make_shared<Test>(val);
}

static void test3()
{
	// 用 new 还是 make_shared，即使禁止优化，现代编译器，也会自动省略一些不必要的函数调用
	//Test::ptr t = std::make_shared<Test>(50);
	Test::ptr t(new Test(50));

	// 如此调用，是 4 次！
	//Test::ptr t2 = GetObject3(t);

	// 换一种，还是四次，嗯嗯，智能指针确实能够帮助开发者，在注重实现功能的同时，
	// 自动兼顾了 实例化对象 时存在的性能问题，嗯嗯！

	// 你可能会思考，智能指针本质上使用类实现了这些繁琐的步骤，方便开发者进行开发，
	// 所以底层会有一些 shared_ptr 的内置函数调用，但是与实际项目中的类构造的
	// 代价相比，这但东西，太小了，几乎不用考虑
	Test::ptr t2 = nullptr;
	t2 = GetObject3(t);

}

int main()
{
	//test1();

	//test2();
/*
* 1、函数参数传递过程中，对象有限按照引用传递(指针也行)，不要按值传递
* 
* 2、函数返回对象的时候，应该有限返回一个临时对象(让编译器自动优化)，而不是返回一个函数体内局部变量
* 
* 3、接收按值返回的函数调用时，有限按照初始化的方式接收 “返回值”，不要按照 “赋值” 的方式接收
* 
* 以上三条均站在 “尽可能少的调用函数来实现功能” 的角度触发，嗯嗯！
* 
*/

/*
* 4、那么我还有疑惑，一般在项目中，对于很多东西，使用的都是 智能指针的方式，传递，实例化对象
*	看看调用了几次吧！
* 
*/

	test3();

	return 0;
}