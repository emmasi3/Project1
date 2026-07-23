#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

/*
* @brief 讨论为什么 shared_ptr(new int(10)); 这种方式的缺陷以及如何解决？
*/
static void test1()
{
	std::shared_ptr<int> ptr1(new int(10));
	// 通过 new int(10); 让智能指针接管资源
	std::shared_ptr<int> ptr2 = std::make_shared<int>(10);
	// 通过 make_shared<int>(10); 直接创建并接管资源，有什么区别？

	// shared_ptr 中，继承了 Ptr_Base，内部保存着 “资源指针” + “引用计数指针”
	// 这俩玩意都是 new 出来的，如果采用手动 new 的方式，相当于在外部 new 出来一块资源
	// 在创建 shared_ptr 这个对象时，还要额外 new 出来存放引用计数指针的内存
	// 存在缺陷：1、如果 new int(10); 没出问题，而创建shared_ptr 的引用计数时出现问题？
	//			很可能会引发 “内存泄漏”
	// 但是使用 std::make_shared() 时，内部会直接将 “资源” + “引用计数” --> 开辟到
	// 同一块内存上，要失败一起失败，要成功一起成功

}

class Person
{
public:
	typedef std::shared_ptr<Person> ptr;

	~Person()
	{
		std::cout << "~Person()" << std::endl;
	}
};

template<typename T>
struct LoggingAllocator
{
	typedef T value_type;

	LoggingAllocator() = default;

	template<typename U>
	LoggingAllocator(const LoggingAllocator<U>&) {}

	T* allocate(std::size_t n)
	{
		std::cout << "allocate_shared 分配内存, n = " << n << ", size = " << n * sizeof(T) << std::endl;
		return std::allocator<T>{}.allocate(n);
	}

	void deallocate(T* p, std::size_t n)
	{
		std::cout << "allocate_shared 释放内存, n = " << n << ", size = " << n * sizeof(T) << std::endl;
		std::allocator<T>{}.deallocate(p, n);
	}

	template<typename U>
	bool operator==(const LoggingAllocator<U>&) const
	{
		return true;
	}

	template<typename U>
	bool operator!=(const LoggingAllocator<U>&) const
	{
		return false;
	}
};

/*
* @brief 讨论 make_shared 的缺点：
*/
static void test2()
{
	/*
	* 1、使用 make_shared 时，可能会有延迟释放现象(和直接 new 作对比)
	*	原理(视频有讲)：
	*	（1）当 资源和引用计数不是同一块内存时：强智能指针计数 --> 0，弱智能计数 != 0;
	*		此时调用 ~Person()，释放资源，计数依然存在 "堆" 上，weak_ptr 依然可以观察，
	*		因为此时，引用计数的内存没有被释放
	*	（2）当 资源和引用计数是同一块堆内存时：强智能指针计数 --> 0，弱智能计数 != 0;
	*		由于此时 “资源 + 引用计数” 在同一块 “内存” 中，所以并不会直接释放内存，因为
	*		还有 weak_ptr 作为观察者，当两个 “计数” 同时归零时，才释放这块内存
	*/

	std::weak_ptr<Person> w_p;
	{
		Person::ptr p1(new Person());
		w_p = p1;
	}

	// 睡眠两秒，保证 weak_ptr 依然存在，此时查看终端控制台打印信息
	std::this_thread::sleep_for(std::chrono::seconds(2));
	// 可以看见，直接显示调用了 ~Person()

	w_p.reset();
	{
		Person::ptr p1 = std::make_shared<Person>();
		w_p = p1;
	}

	// 睡眠两秒，保证 weak_ptr 依然存在，此时查看终端控制台打印信息
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

/*
* @brief 用于更直观看到“对象析构”和“控制块延迟释放”的示例
*/
static void test3()
{
	struct Demo
	{
		~Demo()
		{
			std::cout << "~Demo()" << std::endl;
		}

		static void* operator new(std::size_t size)
		{
			std::cout << "Demo::operator new, size = " << size << std::endl;
			return ::operator new(size);
		}

		static void operator delete(void* p)
		{
			std::cout << "Demo::operator delete" << std::endl;
			::operator delete(p);
		}
	};

	std::weak_ptr<Demo> w;
	{
		std::shared_ptr<Demo> p = std::make_shared<Demo>();
		w = p;
	}

	std::cout << "shared_ptr 已销毁，但 weak_ptr 还在" << std::endl;
	w.reset();
	std::cout << "weak_ptr 也销毁了" << std::endl;
}


int main()
{
	//test1();

	//test2();
	//test3();

	std::string filename = "请选择一个文件";

	/*
	* 总结：
	•	std::make_shared<Person>() 通常会把 对象 Person 和 控制块（强引用计数、弱引用计数）放在同一次分配的内存里
	•	当最后一个 shared_ptr 销毁，强引用计数变为 0 时：
	•	会立刻调用 ~Person()
	•	但这块内存不会马上释放
	•	只有当所有 weak_ptr 也销毁，弱引用计数变为 0 时：
	•	才会释放那块联合分配的内存
	*	1、通过 test2() 可以发现，两种方式，都是在 shared_ptr 计数 -> 0 时，
	*		调用托管对象的 ~Person() 析构函数；
	*		那么这个 ~Person() 是如何被调用的呢？
	*		一般是 delete 时，调用析构函数后使用 “堆内存”；
	*		但是在 shared_ptr / make_shared 的场景下，这两部可能被拆开了
	*	2、基于 1 的猜测，如果是通过 make_shared 使得 “控制块 + 资源” 在
	*		同一块内存中，那么当 shared_ptr 计数 -> 0 时，
	*		仅调用 ~Person() 析构函数，并没有delete 这块内存
	*		因为 还有 weak_ptr 存在，当 weak_ptr 不在观察时，才会释放 “堆内存”
	*		析构 和 delete 可以不是同一个操作
	*	3、make_shared 还有一个缺点，不能够自定义删除器，只能使用 new 的方式
	* 
	* 网址讲解：https://blog.csdn.net/m0_49106549/article/details/146347854
	*/

	return 0;
}
