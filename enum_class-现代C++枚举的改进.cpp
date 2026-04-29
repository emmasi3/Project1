#include <iostream>

static void test()
{
	enum Http
	{
		GET = 1,
		APT = 2,
		CPT = 3,
		III
	};

	enum class HTTPS
	{
		GET = 1,
		APT = 2,
		CPT = 3,
		PPP = 5,
		III
	};

	/*
	* 首先明确 enum 和 enum class 都是枚举类型，只不过前者是 C 风格的，后者是现代 C++ 新添加的
	* 1、enum 的类型自可以 “隐式” 转换为 int，但是 enum class 不行，必须显示转换
	*	并且使用其中的类型时，必须加上明确的 作用域，HTTPS::GET
	*/
	int a = GET;
	int as = (int)HTTPS::GET;

	/*
	* 2、这个 III 在两个 enum 中都没有明确被赋值，它仅仅是作为一个 “哨兵”，保证了当请求或者回答
	*	越界时，如何处理的问题，这个 III 在 enum class 中被自动填充为 6，可以发现，他会比值最大的
	*	枚举值 +1，嗯嗯。
	*	例如： HTTP 中的请求方法，处理不了时，使用 INVALID_METHOD
	*/
}

int main()
{


	return 0;
}