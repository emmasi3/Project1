#include <iostream>
#include <memory>
#include <functional>

static uint64_t count = 100;

class MyDeletor
{
public:
	void operator()(char* ptr)
	{
		std::cout << "MyDeletor 触发！" << '\n';
		delete[] ptr;
		count--;
	}
};

/*
* @brief 删除器 deletor
*/
static void test1()
{
	
	/*
	* 1、仿函数 作删除器
	*/
	{
		std::unique_ptr<char, MyDeletor> ptr(new char[100]);
		// 这个语法有点奇怪啊？如何用  std::make_unique 实现和 使用new 一样的功能
		// 1、我自定义的删除器，我需要调用，因为其中有飞做不可的操作：这里用 count--; 来模拟一下；
		//  
		// 2、我还想要使用 std::make_unique的语法； 这能够做到吗？还是语法根本不允许
		// 嗯，看起来语法不允许，老老实实用 new 吧！
		//std::unique_ptr<char[], MyDeletor> ptr = std::make_unique<char[]>(100);
	}

	/*
	* 2、function + lambda 作删除器
	* @brief 这里尝试是否能够在构造函数中传递删除器 -- 回调函数
	*		这里必须和 unique_ptr 模板参数列表保持一致，否则不行(这和C++标准库中实现有关)
	*/
	{
		std::unique_ptr<char, std::function<void(char* ptr)>> ptr(new char[100], [&](char* ptr) {
			delete[] ptr;
			std::cout << "function(void(char* ptr)) 作为 --> 删除器\n";
			count--;
			});
	}

	/*
	* 3、decltype + lambda 作删除器
	* @brief 模板参数列表直接传递 lambda
	*/
	{
		auto lambda_ = [](char* ptr) {
			delete[] ptr;
			std::cout << "decltype(lambda) 作为 --> 删除器\n";
			count--;
			};

		std::unique_ptr<char, decltype(lambda_)> ptr(new char[100], lambda_);
	}

	std::cout << "test1() End\n";
}

int main()
{
	test1();
	// 判断以上的测试，是否被调用
	std::cout << "count: " << count << '\n';

	/*
	* 总结：
	*	1、对于一些需要用智能指针接管的资源，很多时候，他们的自定义删除行为发生次数
	*		很少，复用性不高，重要程度也不高，嗯，最好接管的时候，就用一个一次性的东西
	*		定义删除行为
	*		推荐使用 test1() 中的 std::function + lambda 形式，这样不需要额外的语句来定义
	*/

	return 0;
}