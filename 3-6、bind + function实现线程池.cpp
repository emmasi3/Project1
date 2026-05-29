#include <iostream>
#include <memory>
#include <functional>
#include <string>

static int sum(int a, int b)
{
	return a + b;
}

static void printf_string(const std::string& str)
{
	std::cout << (str + '\n');
}

/*
* @brief bind -- 占位符
*/
static void test1()
{
	/*
	* 这里应该打印出 3，占位第一个参数
	*/
	{
		std::cout << std::bind(&sum, std::placeholders::_1, 2)(1) << '\n';

		std::bind(&printf_string, std::placeholders::_1)("hello world!");
	}

}

int main()
{
	test1();

	return 0;
}