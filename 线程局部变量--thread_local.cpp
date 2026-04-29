#include <iostream>
#include <mutex>
#include <memory>
#include <thread>
#include <Windows.h>

thread_local int a = 0;

void func1()
{
	for (int i = 0; i < 5; ++i)
	{
		std::thread::id id = std::this_thread::get_id();
		std::cout << "线程：" << id << " 日志计数：" << a++ << " windows的内核线程id:" << " " << (uint32_t)GetCurrentThreadId() << std::endl;
	}

}

/*
* 1、这个 thread_local 修饰的变量，特点：
*	（1）线程私有：每一个线程都会拥有 thread_local 变量的一个副本，保证各个线程间对于该数据，不发生数据竞态
*	（2）与线程生命周期同步
* 
* 2、解决的问题：假设现在有一个日志，log1，log2，log3···，需要在每次调用同一个任务函数时，保证自定义标识 a，不断自增，
*	那么现在难点是，这很多个线程面对的是同一个任务函数，所以 a 在哪儿定义，如何定义就成了难题，保证两点：
*	（1）不发生数据竞态，（2）线程存在期间该变量必须存在，否则无法进行
* 
* 3、thread_local 决定变量“线程独立性”
*	 static 决定变量“文件可见性 / 生命周期”
* 
*	两者作用点不同，不冲突，可以叠加。
* 
*	✅ static thread_local 常用于：线程独立日志缓冲、线程独立统计数据、线程本地对象缓存 等需要隔离访问、又不希望变量在其它文件被访问的场景。
* 
*	但是 static 不会改变 thread_local 的生命周期吗？不会的，只会影响文件可见性
* 
* 4、✅ 并不是所有线程在创建时都会自动生成那份拷贝，
*	而是当某个“线程第一次访问该变量”时，才会为该线程分配并初始化。
* 
*/

int main()
{
	std::thread t1(&func1);
	std::thread t2(&func1);
	t1.detach();
	t2.join();

	return 0;
}
