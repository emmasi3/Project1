#include <iostream>
#include <memory>


static void test1()
{
	std::shared_ptr<int> ptr1(new int(5));


}

int main()
{
	test1();

	/*
	* 1、关于智能指针是否是线程安全的？
	*	（1）带引用计数的智能指针在 “引用计数” 的修改的操作是原子操作，所以引用计数的
	*		修改是 “线程安全” 的
	*		补充：引用计数是一个 atomic_int 原子变量
	*	（2）但是智能指针托管的 “内存 or 资源” 并不是线程安全的，需要开发者使用互斥量
	*	···保证线程安全
	*/

	return 0;
}