#include <sstream>
#include <memory>
#include <iostream>
namespace sylar
{
	class ConfigVarBase
	{
	public:

		ConfigVarBase(const std::string& name, const std::string& description = "")
			:m_name(name),
			m_descirption(description)
		{
			std::cout << "&name" << &name << std::endl;

			std::cout << "之后的：" << &(*(&name)) << std::endl;
		}

		virtual ~ConfigVarBase() {} // 虚析构函数，方便释放内存不出错

		typedef std::shared_ptr<ConfigVarBase> ptr;
	private:
		std::string m_name;
		std::string m_descirption; // 描述（翻译）？
	};


}

void foo(int& x) {
	x = 42;
}

void foo(int* const x_ptr) {
	*x_ptr = 42;
}

int main()
{
	std::string A = "hello";
	std::cout << "&A   " << &A << std::endl;
	
	sylar::ConfigVarBase C(A);

	//1、 可以很清晰的看见，三条语句打印出来的结果是一致的，也就是引用 name 和本体 A，地址一致

	//2、函数 foo ，编译器有可能会将代码优化为，重载 foo 函数，也就是一个常量指针，也就是值可以被修改，但是指向，存储的地址不能被修改，
	//   从这里也可以看出， &(x_ptr) != 传进来的 x 的地址，只是编译器还会继续优化，使得，作用于 引用 X 的所有操作，都会和 本体X一致！！！

	return 0;
}