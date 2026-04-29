#include <iostream>
#include <string>

void fun1()
{
	std::cout << "fun1() 调用 " << std::endl;
}

int main()
{
	int test = 10;

	// 1、typedef 的基本作用就是简化类型名
	unsigned int a = 18;
	std::cout << a << std::endl;
	// 这样的名字有点长了，所以使用它简化一下
	typedef unsigned int UINT32;
	UINT32 b = 18;
	std::cout << b << std::endl;
	// 作用是一样的，对于特别长的类型名，非常有用

	// 2、简化函数指针的使用，这也是我在学习 hook.h 时遇到的语法问题，
	//	  由于 C++ 有 function 语法的存在，所以基本也用不到需要使用 C 风格的函数指针的地方
	//	  这一块也就荒废了，仅仅知道 函数指针 的基本语法，但是用 typedef 来简化函数指针的使用
	//	  这一块知识存在盲区
	void (*f)() = fun1;
	f();
	//	  可以看见，fun1() 被调用，f 就是一个函数指针，指向参数为空，返回值为 void 的fun1的指针
	//	  简化后：
	typedef void(*FUN)();
	FUN ff = fun1;
	ff();
	//	  这里直接使用 typedef 定义一个函数指针类型，看清楚，是类型，不是一个具体的函数指针！！！
	//	  上面的 f 是一个具体的函数指针，可以指向具体的函数地址，可以认为是一个变量名；
	//    下面的 FUN 则是一个函数指针类型，也就是 int ，定义一个具体的变量名，这样子方便一点
	//	  这里的 第2点，可以参考 服务器学习项目 -- hook.h 中的代码
	

	// 3、typedef 和 define 宏定义不一样，他并不是简单的字符串替换，他会对指针做一些处理
	// 这里先了解 “常量指针” -- const int* p; “指针常量” -- int* const p;
	// （1）指向常量的指针 -- 常量指针，所以指针指向的内存，不能被修改，也就是 10 这个值不能修改
	// （2）指针是一个常量 -- 指针常量，const 修饰的是指针指向，指向是一个常量，也就是指针 p 保存的
	//		地址是一个常量，不能被修改，p 不能由 int a，变更指向 int b;
	// 
	typedef int* INTP;
	const INTP pg = &test;
	std::cout << "int test：" << *pg << std::endl;
	// 这里正常打印 10，看他是否能够等价于 -- const int* pg; 标准：如果等价，那么他不能修改内存
	// ，但是可以修改指针指向！
	*pg = 20;
	std::cout << "after int test：" << *pg << std::endl;
	// 可以看见，也成功了 ，是20
	// pg = nullptr;  改变指针指向的时候，让其从 &test 变为 nullptr 时，报错了
	// 所以说：const INTPpg != const int* pg; 而是等于 int* const pg;
	// 由此可见，typedef 本质和 define 不一样，不是简单的文本替换，还做了一些特殊的处理
	

	return 0;
}
