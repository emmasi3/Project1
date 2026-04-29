#include <iostream>
#include <string>
#include <functional>
#include <vector>

typedef int pthread_t;

namespace sylar
{

	class Scheduler
	{
	public:
		template<class FiberOrCb>
		void scheduler(FiberOrCb fc, pthread_t thread = -1)
		{
			std::cout << "你调用了 FiberOrCb -- scheduler\n";
		}

		template<class InputIterator>
		void scheduler(std::vector<InputIterator> begin, InputIterator end)
		{
			std::cout << "你调用了 InputIterator -- scheduler\n";
		}

		template<class T>
		void f2()
		{
			std::cout << "你调用了 f2 -- scheduler\n";
		}

	};

	class IOManager : public Scheduler
	{
	public:
		void f1(int f = -1)
		{
			std::cout << "IOManager::f1 运行了\n";
		}
	};

}

static unsigned int sleep()
{
	sylar::IOManager iom;

	std::function<void()> cb = std::bind((void(sylar::Scheduler::*)
						(int, pthread_t thread)) &sylar::IOManager::scheduler,
						iom, 1, -1);

	std::function<void()> cb2 = std::bind(&sylar::IOManager::f1, iom, -1);

	std::function<void()> cb3 = std::bind(&sylar::Scheduler::f2<int>, iom);
	/*无法从“std::_Binder<std::_Unforced,void (__cdecl sylar::Scheduler::* )(void),sylar::IOManager &,int>”转换为“std::function<void (void)>”*/
	cb();
	cb2();
	cb3();

	return 0;
}


int main(int aggc, char* argv[])
{
	std::cout << "你好，成员函数指针" << std::endl;
	/*
	* 1、之所以要创建这个 成员函数指针 知识点讲解，都是因为 服务器项目中 hook.cpp 中遇到了类似
	*	的问题，pthread_t 为 Linux 下的专用类型，这里使用 typedef int pthread_t; 暂时代替
	*	
	*	问题：使用 bind 函数想要将 scheduler 函数绑定，以便于放入定时器中执行，但是一直报错
	*		显示找不到匹配的函数，no match
	*	解决：将参数类型中的 int 改为 pthread_t，也就是 线程id 的参数，这里仅做参考，你只需要
	*		知道，就是因为在 Linux 的某些架构平台中，pthread_t != int，所以必须用 pthread_t
	*	但是，这仅仅是表象地解决了问题，至于为什么，涉及到什么内容，慢慢来讲：
	* （1）首先去了解 类的成员函数指针的知识点：也就是下面的例子
	*	你可以了解到成员函数指针的一些用法
	* （2）bind 是一个模板函数，使用了可变参数包，一般第一个参数为 -- 函数指针或者函数地址，这里使用了 成员函数指针
	*	强制转换了一个 成员函数地址，&sylar::IOManager::scheduler，如果直接使用地址呢？会怎样？
	*	会直接报错，即使绑定实例化对象 iom 也不行，你会想：那么其他普通非模板函数这样子也不行吗？
	*	如：cb2()，很显然，行，直接用地址就行，会自动转换，所以应该是 scheduler 是模板函数的原因
	*	再看 cb3()，使用了模板函数，也是直接使用地址，报错了吗？没有，因为我指定了具体的模板参数，它能够初始化为具体函数了
	*	嗯嗯，
	*	再看 cb()，其实他也是间接地指定了模板参数，因为 scheduler 函数的参数列表中，使用了模板参数来定义形参，所有触发了 自动推导
	*	所以才不会报错的
	* （3）cb 的参数列表中，为什么有 pthread_t thread; 有一个参数名？这允许吗？是允许的，改为 (int, pthread_t) 也是可以的， thread 会被编译器忽视
	*	嗯嗯，这里应该全部讲清楚了，去看看 成员函数指针的具体用法吧！尤其是 运算符--  .*  --and--  ->*  --，使用有点复杂，但是在有些情况下
	*	必须使用该方法（我还没遇到），服务器项目中的 bind 逻辑，完全可以用 lambda 表达式代替，而且更加地简洁、清晰、高效
	* 
	*/
	sleep();

	////////////////////// 类的成员函数指针 -- 使用方式（2种）///////////////////////////
	sylar::IOManager iom;
	sylar::IOManager* iom2 = new sylar::IOManager;
	void (sylar::IOManager:: * pf1)(int) = nullptr;
	pf1 = &sylar::IOManager::f1;
	// 调用方式
	// (1) 括号不能少
	(iom.*pf1)(1);
	// (2) 括号不能少
	(iom2->*pf1)(1);
	delete iom2;
	///////////////////////////////////////////////////////////////////////////////////

	return 0;
}