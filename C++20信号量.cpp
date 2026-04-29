#include <iostream>
#include <string>
#include <thread>
#include <semaphore>
#include <vector>

std::counting_semaphore<5> sem(5);
std::vector<std::thread> thrs;

/*
* 1、semaphore信号量，主要对象   std::counting_semaphore<100> sem(10)
*	<100>模板参数，标记“最大许可数”，构造函数中 10 表示初始化sem时，就可以减少的“计数（许可数）”，
*	假设：停车场 sem，最大容量 100，开始时，只有10个空闲停车位，嗯嗯，好理解了
* 
* 2、进入停车场后，停车者（线程）争夺停车位（共享资源 -- 读写--音视频缓冲区buffer），很明显，
*	此时，单纯的信号量无法轻易解决这个问题，所以要用到互斥量(mutex)，也就是加锁，来解决“数据竞态”
* 
* 3、信号量限流、互斥量···不知道
* 
*/

void f()
{
	sem.acquire();

	std::cout << "thread_id: " << std::this_thread::get_id() << std::endl;

	sem.release();
}

int main()
{

	for (int i = 0; i < 5; ++i)
	{
		thrs.emplace_back(std::thread(&f));
	}

	for (auto& i : thrs)
	{
		if (i.joinable())
			i.join();
	}

	return 0;
}