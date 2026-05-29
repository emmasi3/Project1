#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <list>
#include <string>

template<class F, class T>
class LexicalCast
{
public:
	void operator()(F f, T t)
	{
		std::cout << "LexicalCast<F, T>" << '\n';
	}
};


/*
* @brief 关于全特化和偏特化的知识，在 project1 中有总结，去看，这里不再赘述
*/
static void test1()
{
	LexicalCast<int, double>()(1, 1.0);
}

static int test2_1(double d, const std::string& str)
{
	std::cout << "test2_1 hello\n";
	return (int)d;
}

/*
* @brief 这里可以了解一下 “函数类型” 和 “函数指针类型” -- diff
*/
static void test2()
{
	// 这里传递的是 “函数指针类型”
	LexicalCast<int, int(*)(double, const std::string&)>()(1, &test2_1);

	// 这里传递的是 “函数类型”
	LexicalCast<int, int(double, const std::string&)>()(1, &test2_1);

	// 相比较而言，“函数类型” 更加灵活一些，因为 C++11 中给出了 bind + function
	// 的组合，有专门处理 “函数类型” 的 function 类，传递，调用，存储，都符合人的
	// 主观感受，嗯嗯
}

/*
* @brief 这里模拟 std::function<> 则个类的底层原理
*		：模板 + 函数指针 + 函数类型 + 可变参数包
* @param R 为返回值类型，A... 为可变参数包
* @note 想要有 “特化” 版本，就必须首先定义一个 “泛化” 版本，也就是主版本，否则编译器不允许 
*/
template<class Signature>
class MyFunction;

/*
* @brief 这里模拟 std::function<> 则个类的底层原理
*		：模板 + 函数指针 + 函数类型 + 可变参数包
* @param R 为返回值类型，A... 为可变参数包
* @note 特化版本，使得 MyFunction 的模板参数列表仅需一个 “函数类型” 即可
*		如果没有这样的一个 “特化” 版本，传递函数类型时，会自动将 “函数类型”
*		作为 R，而另一个 ... A 参数包没有东西，就会报错，达不到使用要求
*		所谓 “特化” 就是对 “模板参数列表” 的接收程度做调整
*/
template<class R, class... A>
class MyFunction<R(A...)>
{
public:
	using RFUNC = R(*)(A...);

	MyFunction(RFUNC pfunc) : _pfunc(pfunc) {}

	R operator()(A... arg)
	{
		return _pfunc(arg...);
	}

private:
	// 具体的方法
	RFUNC _pfunc;
};

static int sun(const std::string& str, double f)
{
	std::cout << str << ' ' << f << '\n';
	return 0;
}

/*
* @brief 测试 MyFunction 以及总结用法
*/
static void test3()
{
	std::string str = "你好世界";
	auto foo = [](const std::string& str, double f)->int {
		std::cout << str << ' ' << f << '\n';
		return 0;
		};

	MyFunction<int(const std::string&, double)> func1(&sun);
	func1(str, 3.14);

	MyFunction<int(const std::string&, double)> func2(foo);
	func2(str, 5.48);
}

int main()
{
	test1();

	test2();

	test3();

	return 0;
}