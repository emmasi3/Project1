#include <iostream>


class Test
{
public:
	// 构造函数
	Test(int a = 10) : ma(a) { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
	Test(const Test& t) : ma(t.ma) { std::cout << "Test(const Test&)" << std::endl; }
	
	// 重载的成员函数 != 构造函数
	// “浅拷贝”
	Test& operator=(const Test& t)
	{
		ma = t.ma;
		std::cout << "operator= " << ma << std::endl;
		return *this;
	}

private:
	int ma;
};

static void test1()
{
	Test t1(20);

	// 最直观的拷贝构造
	Test tt(t1);

	// 这里应该是拷贝构造，但是我当时是有疑惑的？或者说，一直以来都有种错误的
	//  “直觉” -- = 号，就是要调用 = 赋值构造函数
	// 但是这里有个致命的错误：这里是在利用 t1 构造新的实例化对象 t3
	// 重点是 “构造” 二字，如果这里真的采用 “= 重载函数”，那么语义必然矛盾
	// 所以 “ = 赋值构造函数” 这个说法本身就是错误的！
	Test t3 = t1;

	// 在编译器禁止 “优化” 的前提下，但从语法结构分析：1、首先进行一次
	// Test() 有参构造；2、进行拷贝构造；3、调用析构释放 “临时对象”
	// 但是结果显示，该语句仅仅调用了一次有参构造，也就是编译器为了减少调用
	// 的损耗，优化为了一次构造调用
	Test t2 = Test(20);

	// 不涉及 “构造语义”
	// 这里才是真正的 = 重载函数的调用！不会调用 “构造函数”
	t3 = t1;

	// 分析：涉及到 t3 的operator=() 重载函数，所以对于 t3来说，肯定不是构造
	// 对于 “临时对象” 来说，涉及到有参构造，这步构造能省略吗？不能
	// 因为 t3.operator() 需要接受一个对象的引用，如果 Test(55) 都不构造，
	// 哪里来的对象给到 =重载函数参数，之后便是调用 有参构造 --> operator=()
	t3 = Test(55);

	std::cout << "\t---------\t" << std::endl;

	// 分析：涉及到 t3 的 operator=()，不涉及到 t3 的构造，
	// 30 不是一个 Test 类型的对象，而是一个 int 型临时变量，
	// 但是经过了强制转换 (Test)30，首先编译器会检测 Test 构造函数是否够能够接受这样的一个 int 参数
	// 如果能，有参构造一个 “临时 Test 对象”，引用作为参数给到 operator=()
	t3 = (Test)30;

	std::cout << "------------" << std::endl;

	// 这个和上面的情况一样
	t3 = 30;
}

static void test2()
{
	// c++ 新标准会报错：“&”要求左值
	// Test* p = &Test(40);

	// 这里必须用 非常量引用，也就是 const Test& ref; 否则直接报错
	// 运行结果显示，Test() 构造函数执行之后，并不是当做 “临时对象”
	// 在 ---------- 之前析构，而是在本作用域结束后才析构，const 常量引用
	// 强制将一个 Test(50) 临时变量 --> 局部变量(栈区)，这样引用才有更长的
	// 生命周期
	const Test& ref = Test(50);

	std::cout << "-------------\n";



	std::cout << "-------------\n";
}

int main()
{
	//test1();

	test2();

	return 0;
}