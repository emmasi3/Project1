#include <iostream>
#include <memory>

static void test1()
{
	std::cout << "===== test1: shared_ptr 循环引用复现 =====\n";

	struct B;
	struct A
	{
		std::shared_ptr<B> pb;
		~A() { std::cout << "A 析构\n"; }
	};

	struct B
	{
		std::shared_ptr<A> pa;
		~B() { std::cout << "B 析构\n"; }
	};


	/*
	* 1、疑惑：思考，后构造 -- 先析构，那么在 b 调用析构函数时，b 的引用计数肯定 -1 是吧？
	*	也就是从 2 --> 1，那么同时 B 不是有成员 shared_ptr<A> pa; 嘛？难道 B 析构的时候
	*	不释放 pa？也就是不触发 pa 的析构使得 a 的引用计数 -1，从 2 --> 1，
	*	那么同理，a析构的时候，引用计数直接清 0 了，触发 A、B 的析构
	*	我当时就是这么想的，我的意思是：现在这种情况不会触发 “交叉引用” 问题。错！！！会触发
	* 
	*	分析：auto a = std::make_shared<A>();
	*		  auto b = std::make_shared<B>();
	*		当前作用域中，仅仅创建了 1个 A 和 1个 B！
	*		也就是 A、B 的析构函数，无论如何也只会 调用 1次是吧？
	*		那你再看看上面的 “疑惑” 中的描述，析构析构，调用的到底是谁的析构？
	*		b 在出作用域时，调用的析构函数是 --> shared_ptr<B> 这个标准类的析构
	*		不是 struct B::~B(); 看清楚了吧？直到上面的 “疑惑” 错到哪儿了吧？
	*		让我们来再次分析。
	*		（1）b出作用域，调用 shared_ptr<B>::~() 的析构，资源B引用计数 2 --> 1;
	*		（2）a出作用域，调用 shared_ptr<A>::~() 的析构，资源A引用计数 2 --> 1;
	*		好了，B 和 A 的引用计数都没有清 0，析构函数都没有调用
	*	
	*/
	{
		auto a = std::make_shared<A>();
		auto b = std::make_shared<B>();

		a->pb = b;
		b->pa = a;

		std::cout << "a.use_count = " << a.use_count() << "\n";
		std::cout << "b.use_count = " << b.use_count() << "\n";
		std::cout << "离开作用域后，若析构函数未打印，说明发生循环引用导致资源无法释放。\n";
	}

	std::cout << "test1 结束\n\n";
}

static void test2()
{
	std::cout << "===== test2: 使用 weak_ptr 断开循环 =====\n";

	struct B;
	struct A
	{
		std::shared_ptr<B> pb;
		~A() { std::cout << "A 析构\n"; }
	};

	struct B
	{
		std::weak_ptr<A> pa;
		~B() { std::cout << "B 析构\n"; }
	};

	{
		auto a = std::make_shared<A>();
		auto b = std::make_shared<B>();

		a->pb = b;
		b->pa = a;

		std::cout << "a.use_count = " << a.use_count() << "（weak_ptr 不增加引用计数）\n";
		std::cout << "b.use_count = " << b.use_count() << "\n";

		if (auto lockedA = b->pa.lock())
		{
			std::cout << "通过 weak_ptr::lock() 可安全访问 A，lockedA.use_count = " << lockedA.use_count() << "\n";
		}
	}

	std::cout << "离开作用域后，A/B 均可正常析构，循环被打破。\n";
	std::cout << "test2 结束\n\n";
}

int main()
{
	//test1();
	test2();

	/*
	* 1、shared_ptr 强智能指针：拷贝、构造 --> 增加引用计数
	*	（1）重载了 * = -> ··· 运算符，可以和使用 “裸” 指针一样，访问、修改资源
	* 
	* 2、weak_ptr   弱智能指针：拷贝、构造 --> 不增加引用计数
	*	（1）未重载常用运算符，不能访问，修改资源，只能访问引用计数
	*	（2）在引用计数为 0 和 !0 时，可表现出不同的行为
	*	（3）提供 lock() 方法，返回对应资源的 “shared_ptr”，安全的访问、修改资源
	*		观察者(体现)：如果调用 lock() 时，该资源的引用计数 --> 0，会返回 nulltpr
	*					这也是 “安全” 的体现
	*/

	std::cout << "===== main 总结 =====\n";
	std::cout << "1) shared_ptr 采用引用计数管理对象。\n";
	std::cout << "2) 双向都用 shared_ptr 时，计数可能互相持有而永不归零，产生循环引用。\n";
	std::cout << "3) 常见解决方案：一侧改为 weak_ptr（观察者），不参与所有权计数。\n";
	std::cout << "4) 访问 weak_ptr 指向对象前应 lock()，判断对象是否仍存活。\n";
	std::cout << "5) 设计原则：明确“谁拥有对象”，避免无意义的双向强拥有关系。\n";

	return 0;
}