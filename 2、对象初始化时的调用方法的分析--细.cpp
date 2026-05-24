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

	int getData() const { return ma; }

private:
	int ma;
};

static Test GetObject(Test t)
{
	int val = t.getData();
	Test tmp(val);
	return tmp;
}

static void test1()
{
	Test t1;
	Test t2;
	t2 = GetObject(t1);
}

int main()
{
	test1();

	// 问：从 test1() 到退出 test1()释放栈区资源，一共发生过多少次构造？
	// 都是什么类型？析构次数有多少？
	// 答案：额，看 学习_picture_辅助理解 -- 2、png 图片

	// 值得注意的点：1、t2 = GetObject(t1); 传递的 t1 是一个对象
	// 方法的形参类型是 Test，那么语义是 “赋值” or “构造” 呢？
	// 很明显是 “构造” 嘛，赋值针对的是已经存在的对象，形参 Test t
	// 很明显还没有被创建嘛，所以这一步是 “拷贝构造”

	// 2、return tmp; 需要返回的是 Test 类型，但是 tmp 是局部变量
	// 所以会先 构造一个 “临时变量”，返回时要析构 tmp，之后再调用
	// t2 的 operator=() 赋值方法，!= 构造

	return 0;
}