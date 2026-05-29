#include <iostream>

template<class F,class T>
class Person
{
public:
	Person()
	{
		std::cout << "泛化版本" << std::endl;
	}
};

template<class F>
class Person<F, double>
{
public:
	Person()
	{
		std::cout << "偏特化版本 -- F，double" << std::endl;
	}
};

//template<class M>
//class Person<M, double>
//{
//	Person()
//	{
//		std::cout << "特化版本 -- M，double" << std::endl;
//	}
//};
// 报错，显示已定义
template<>
class Person<int, double>
{
public:
	Person()
		:a(1),b(2.0)
	{
		std::cout << "特化版本 -- int，double" << std::endl;
	}

public:
	int a;
	double b;
};

template<class F, class T>
class Person<F*, T>
{
public:
	Person()
	{
		std::cout << "针对指针类型的偏特化版本 -- F*，T" << std::endl;
	}
};

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


int main()
{
	Person<int, double>();
	Person<int, double>();

	// 偏特化特例：F* 针对指针类型的偏特化
	// Person<int*, double>(); 这个会报错，因为上面有 class Person<F, double>，有歧义！
	Person<int*, char*>();

	return 0;
}
/*
* 1、类模板本身有一个泛化版本，所谓“特化”，就是泛化中的特殊情况，所以这就不难理解了
*    手动指定类模板参数中的一个或者多个为具体类型，这就是特化或者“偏特化”
* 2、如上述所写，你可以运行一下，现在应该全部都会打印 特化版本 -- int, double，
*    当你使用 Person<int, double> 时，编译器会根据你的所有类模板版本（包括泛化），去看有没有哪一个 特化版本，
*    拥有 int, double 中的一个或者两个，从而选择去生成相应的“类模板版本”
* 3、目的：你也能看出来，之所以要特化这个东西，就是为了应对一些特殊的情况，不好用“泛型版本”解决的问题，
*          直接用特化版本，实现区别于“泛化”的功能，就不用再写其他的“类”来实现相应的功能了，本质是提高代码的
*          复用性、可维护性
* 4、模板这块报错，一般都是编译器不知道选择哪一个版本，也就是各种版本的模板之间存在 “歧义”
* 
* 5、这里的 MyFunction 也算一种 “特化” 版本，特化不一定是 “显式地” 指定模板参数列表的
*	类型，还可以是对模板参数 做调整，只要这个调整合理，都算是 “特化”
*/