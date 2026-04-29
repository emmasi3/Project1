#include <iostream>
#include <string>
#include <sstream>
#include <thread>
using namespace std;

int main()
{
	stringstream ss;
	ss << "hello," << "world" << 122 << 456;
	cout << ss.str() << endl;

	string s;
	s = "hello,world";
	s += to_string(122456);
	cout << s << endl;

	//三、clear()只是重置状态，不能清除内容
	ss.clear();
	std::cout << ss.str() << std::endl;
	//这里依旧会打印出 hello,world122456，那么这个东西用在什么地方呢？
	string a1;
	ss >> a1;
	ss >> a1;
	ss.clear(); // 这里用来重置错误状态，嗯嗯
	cout << a1;
	//（三）如何重置呢？
	ss.str("");
	//这样重置stringstream，嗯嗯

	//四、关于线程id的流信息注入
	std::thread::id a = std::this_thread::get_id();
	ss << a;

	std::cout << "线程id：" << a << std::endl;
	std::cout << "用 stringstream 转换后的线程id：" << ss.str() << std::endl;
	std::cout << 1 << std::endl;

	std::stringstream bb;
	bb << 123456;
	std::cout << bb.str();
	/*
		一、
		hello,world122456
		hello,world122456
		这就是ss和s的输出，不同的方法，但是是同一种表现形式，嗯嗯
		很明显，ss 也就是 stringstream 字符流更加便利，因为是流式的，比操作string的实例化对像更加方便，
		ss也可以被认为是 内存中开辟了一段

		当然，我在用这个的时候，仅仅局限于获取想要的日志信息而已： ss.str()，会返回string类型的字符串对象，嗯嗯，简单易用

		二、
		stringstream 是 ostream 的一个子类，所以可以用一个ostream参数类型来接收一个 stringstream 的参数，也可以是网络、控制台···等等东西
		嗯嗯，这是以前没有注意到的
	*/

	return 0;
}