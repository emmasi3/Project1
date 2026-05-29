#include <iostream>
#include <string>
#include <memory>

// 1) 用“仿函数类”模拟最简单的 lambda 实现原理：
//    编译器会把 lambda 变成一个匿名类对象，并把捕获变量变成该类的数据成员。
class AddN
{
public:
	explicit AddN(int n) : n_(n) {}

	int operator()(int x) const
	{
		return x + n_;
	}

private:
	int n_; // 类似于 lambda 的值捕获成员
};

static void test1()
{
	std::cout << "===== 1. 最简单的lambda实现原理（仿函数）=====\n";
	int n = 10;

	// 等价思想：auto f = [n](int x){ return x + n; };
	AddN f(n);
	std::cout << "f(5) = " << f(5) << "\n\n";

	std::cout << "===== 2. 捕获列表基础 =====\n";
	int a = 1;
	int b = 2;

	// 测试A：值捕获 [a]
	// 说明：a 会拷贝到闭包对象中，默认 operator() 是 const，
	// 因此在 lambda 体内不能修改这份“成员副本”。
	auto byValue = [a]() {
		// a++; // 取消注释会编译错误：因为默认是 const 调用运算符
		std::cout << "[a] inside = " << a << "\n";
	};
	byValue();
	std::cout << "[a] outside = " << a << "\n\n";

	// 测试B：引用捕获 [&b]
	// 说明：lambda 内外访问的是同一个变量，可修改外部 b。
	auto byRef = [&b]() {
		b++;
		std::cout << "[&b] inside(after++) = " << b << "\n";
	};
	byRef();
	std::cout << "[&b] outside(after call) = " << b << "\n\n";

	// 测试C：值捕获 + mutable
	// 说明：mutable 会让 operator() 不是 const，
	// 可以修改“捕获副本”，但不影响外部变量。
	auto byValueMutable = [a]() mutable {
		a++;
		std::cout << "[a] mutable inside(after++) = " << a << "\n";
	};
	byValueMutable();
	std::cout << "outside a still = " << a << "\n\n";

	// 测试D：混合捕获 [a, &b]
	// 说明：a 是副本，b 是引用。
	auto mixed = [a, &b]() mutable {
		a += 10; // 改的是副本
		b += 10; // 改的是外部变量
		std::cout << "mixed inside: a(copy)=" << a << ", b(ref)=" << b << "\n";
	};
	mixed();
	std::cout << "mixed outside: a(original)=" << a << ", b(original)=" << b << "\n\n";

	// 回答你的问题：
	// “值捕获的变量为什么默认不能在表达式内部修改？”
	// 原理：
	// 1) 值捕获本质是把外部变量拷贝到闭包对象成员；
	// 2) lambda 默认生成的 operator() 是 const 成员函数；
	// 3) const 成员函数中不能修改成员，所以值捕获成员不能改；
	// 4) 需要修改副本时，用 mutable 去掉这个 const 限制。
}

int main()
{
	test1();

	// ================== 总结（回顾用） ==================
	// 1. lambda 本质：
	//    - 编译器生成一个“匿名类（闭包类型）”对象；
	//    - [] 捕获列表 -> 匿名类的数据成员；
	//    - () 参数列表 + {} 函数体 -> operator()。
	//
	// 2. 捕获列表常见写法：
	//    - [x]     ：按值捕获 x（拷贝）
	//    - [&x]    ：按引用捕获 x（可改外部）
	//    - [=]     ：默认按值捕获外部变量
	//    - [&]     ：默认按引用捕获外部变量
	//    - [x, &y] ：混合捕获
	//
	// 3. 注意事项：
	//    - 值捕获默认不能改（默认 operator() const），若要改副本请加 mutable；
	//    - 引用捕获要注意生命周期，避免悬空引用；
	//    - 只需简单回调时优先 lambda，可读性通常更好。

	return 0;
}
