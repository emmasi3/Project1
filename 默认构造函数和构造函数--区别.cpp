#include <iostream>

class Person
{
public:
	
};

int main()
{
	// 1、编译器自己生成的 -- 默认构造函数
	Person a;

	// 2、自己写的 Person() { std::cout<< "你好世界" << std::endl;  } -- 也算默认构造函数

	// 3、标准： 可以无参调用的构造函数，不管是你手写的还是编译器自动生成的。

	// 4、Person(int x = 0) {} 有默认参数的也算 -- 默认构造函数

	// 5、Person(int x) {} 这就算是 -- 构造函数了 
	return 0;
}