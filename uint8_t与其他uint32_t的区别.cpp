#include <iostream>
#include <string>

static void test()
{
	uint8_t v = 65;
	std::cout << v << std::endl;
	// 1、这里你期望看到的是输出 65，但是很抱歉，它输出了 A ，字符，因为
	//	uint8_t === unsigned char; 他会被当成字符来处理，而不是数值

	int vv = 65;
	std::cout << vv << " (unsigned char) " << (unsigned char)vv << std::endl;
	// 2、在这里使用强制类型转换，也输出了 A，1的想法正确（事实也是如此）

	uint16_t a = 65;
	std::cout << a << std::endl;
	uint32_t a1 = 65; uint64_t a2 = 65;
	std::cout << a1 << std::endl; std::cout << a2 << std::endl;

	// 综上，可以看出，只有 uint8_t 被处理为字符类型，其余都是 数值
	// 这和内部实现有关，记得就好，这个细节有时候非常有用
}

int main()
{
	test();

	return 0;
}