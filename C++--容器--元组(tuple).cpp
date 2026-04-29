#include <iostream>
#include <tuple>

int main()
{
	std::tuple<std::string, std::string, int> t;
	t = { "1","23",45 };

	//1、访问tuple中某一个元素的具体值时，“唯一的”访问方式 -- std::get<>()
	std::cout << std::get<2>(t) << std::endl;

	//2、已知类型，取出元素
	std::string t_s1; std::string t_s2; int t_int;
	std::tie(t_s1, t_s2, t_int) = t;
	std::cout << t_s1 << " " << t_s2 << " " << t_int << std::endl;

	//3、未知类型，取出数据
	auto [s, ss, a] = t;
	std::cout << s << " " << ss << " " << a << std::endl;

	//4、未知类型，引用数据
	auto& [s1, s2, int1] = t;
	std::cout << s1 << " " << s2 << " " << int1 << std::endl;

	return 0;
}