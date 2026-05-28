#include <iostream>
#include <string>


/*
* @brief 模拟在网络IO中，将一个特别长的消息，传递给另一个string对象，也就是要交给其余对象
*		方便后续操作
* @param str 一般访问类的 string 成员，返回的是 const std::string& 类型
*/
static void getString(std::string& str)
{
	// 现在看，str_1 必然经过了 “拷贝构造”，嗯，性能损耗
	std::string str_1 = str;

	std::cout << "str: " << str << "\n";
	std::cout << "str_1: " << str_1 << "\n";

	// 经过 std::move() 转移所有权之后，str / m_str 不在拥有那块内存
	std::string str_move = std::move(str);

	std::cout << "move after str: " << str << "\n";
	std::cout << "str_move: " << str_move << "\n";
	std::cout << static_cast<const void*>(&str_move[0]) << '\n';

}

/*
* 1、测试目的：想看看通过 std::move() 处理过后的字符串 m_str 的底层字符串是否真的转移了所有权
*	手段：打印出 m_str 的底层字符串首字符地址，然后与str_move的底层地址作对比，一致的话，就是移动了所有权
* 
* 2、如何在 C++ 中打印出字符串地址？
* 
* 总结：
*	1、（1）对于一个 std::string& 的类型，直接使用 std::move(str)，那么确实会转移所有权，现象：在执行 std::move 之前的 str 的字符串地址
*		和之后的地址不一致，嗯，那个地址是随机的，因为已经移动了
*	（2）如果是 const std::string& str; 那么 std::move() 不会起作用，他只会调用 “拷贝构造”，现象：在执行 move 之前之后，str 的字符串地址
*		没变，并且 str_move move()过来的字符串地址，和 str 的不一致，所以肯定调用了 拷贝构造
*/
static void test1()
{
	std::string m_str = "str_to_str_dsaondoa";

	const char* a = "nisoda";
	std::cout << &(*a) << '\n';
	// 看下此时 m_str 的保存的字符串地址
	std::cout << &(*m_str.begin()) << std::endl;
	std::cout << &(*m_str.c_str()) << std::endl;
	std::cout << &(*m_str.data()) << '\n';

	// 很明显，上述手段都不行，思路：通过解引用拿到首字符，然后 对其取地址，获取地址，但是 C++ 默认接收字符地址时，打印出 '\0' 
	// 之前的字符串，也就是不会打印出 “地址”

	// 使用 printf("%p\n", m_str.c_str());
	 printf("%p\n", m_str.c_str());
	// 使用 静态强制转换 static_cast<const void*>，或者直接强转
	std::cout << static_cast<const void*>(&m_str[0]) << '\n';

	char* ptr = m_str.data();
	std::cout << "ptr: " << &(*ptr) << '\n';

	getString(m_str);

	std::cout << "move after m_str: " << m_str << "\n";
	std::cout << static_cast<const void*>(&m_str[0]) << '\n';
}


int main()
{
	test1();

	return 0;
}