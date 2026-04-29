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


int main()
{
	Person<int, double>();
	Person<int, double>();

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
* 
*/