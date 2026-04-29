#include <iostream>
#include <thread>
#include <chrono>

static void test_flush()
{
	// 可能 5s 之内，终端不会输出任何东西
	std::cout << "start...";
	std::cout.flush();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "end\n";
	// 好吧，失败了，C++标准并没有规定 std::cout 一定要在缓冲区满了才输出，嗯，换到 linux 平台试一下！
	// 在 E:\音视频\B站服务器开发--学习--80节课\网络编程vs2026_Linux\网络编程vs2026_Linux.slnx 中同名文件

	// 果然，是平台的问题，在 Linux 上运行时，和期望一样，在没有 	std::cout.flush(); 之前
	// 也就是 5s 睡眠结束之前，start... 不会提前输出，也就是缓存输出策略符合猜想，两个平台有差异
}

int main()
{
	test_flush();

	/*
	* 一、flush 出现的背景与原因
	* 1️⃣ 为什么需要 flush

		std::cout 是 带缓冲的输出流

		输出内容不会立刻写到终端或文件

		数据会先进入 用户态缓冲区

		👉 flush 的作用：

		强制将输出缓冲区中的内容立即写入到底层设备（终端 / 文件 / 管道）
	* 2️⃣ 不使用 flush 会出现什么问题

		在以下场景中，输出可能“看不到”或“延迟出现”：

		程序是 长期运行 的（如服务器）

		输出内容 没有换行符

		输出流被 重定向到文件或管道

		希望实时观察程序行为（调试、日志）
	* 
	* 3、程序自动调用 flush 的时机（重点）
		标准规定 & 常见实现行为

		std::cout 会在以下情况下自动 flush：

		输出 std::endl

		程序正常退出

		缓冲区被写满

		流与 stdin 绑定（tie）

		典型行为：

		std::cout << "input: ";
		std::cin >> x;   // cin 前会自动 flush cout

		显式调用 std::flush / flush()

		⚠️ 注意：

		输出 '\n' 不保证 flush

		是否行缓冲 / 全缓冲 与平台、是否连接终端有关
	* 
	* 
	* 
	* 
	*/

	
	return 0;
}