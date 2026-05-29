#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

// 知识点：atomic的基本读写（load/store）。
// 问题：普通变量在多线程下可能出现数据竞争。
// 思路：用std::atomic保证读写是原子的。
// 注意：atomic只能保证单次操作原子性，不等于复合操作一定安全。
static void test1()
{
	atomic<int> value{ 0 };
	value.store(10);
	cout << "test1 value = " << value.load() << endl;
}

// 知识点：atomic自增/自减与fetch_add/fetch_sub。
// 问题：++i在多线程中可能丢失更新。
// 思路：使用原子递增接口完成计数。
// 注意：fetch_add返回的是操作前的值。
static void test2()
{
	atomic<int> counter{ 0 };
	cout << "test2 fetch_add old = " << counter.fetch_add(1) << endl;
	cout << "test2 counter = " << counter.load() << endl;
	cout << "test2 ++counter = " << ++counter << endl;
}

// 知识点：atomic交换操作exchange。
// 问题：需要把旧值和新值一次性原子替换。
// 思路：exchange返回旧值，并把新值写入。
// 注意：适合做状态切换，但不要用它替代所有同步逻辑。
static void test3()
{
	atomic<int> flag{ 1 };
	int oldValue = flag.exchange(5);
	cout << "test3 oldValue = " << oldValue << ", flag = " << flag.load() << endl;
}

// 知识点：CAS（compare_exchange_strong）。
// 问题：只有当当前值等于期望值时才允许修改。
// 思路：CAS成功则替换，失败则把当前值写回expected。
// 注意：expected会在失败时被自动更新，使用前要理解这一点。
static void test4()
{
	atomic<int> value{ 100 };
	int expected = 100;
	bool ok = value.compare_exchange_strong(expected, 200);
	cout << "test4 ok = " << ok << ", value = " << value.load() << ", expected = " << expected << endl;

	expected = 100;
	ok = value.compare_exchange_strong(expected, 300);
	cout << "test4 ok2 = " << ok << ", value = " << value.load() << ", expected = " << expected << endl;
}

// 知识点：CAS常见用法——自旋重试更新。
// 问题：多个线程同时修改同一个值时，单次CAS可能失败。
// 思路：循环读取旧值并重试，直到更新成功。
// 注意：weak可能出现伪失败，适合放在循环里使用。
static void test5()
{
	atomic<int> value{ 0 };
	int expected = value.load();
	while (!value.compare_exchange_weak(expected, expected + 1))
	{
		// expected会被自动刷新为当前值，直接重试即可。

	}
	cout << "test5 value = " << value.load() << endl;
}

// 知识点：atomic_flag与test_and_set/clear。
// 问题：需要一个轻量级的自旋标记。
// 思路：test_and_set原子地置位并返回旧值，clear释放。
// 注意：atomic_flag常用于 "自旋锁"，但忙等会占用CPU。
/*
* 1、使用 atomic_flag 实现 “自旋锁” 的逻辑：
*	（1）初始化 atomic_flag flag = ATOMIC_FLAG_INIT;
*	（2）在封装的 lock() 方法中，使用 flag.test_and_set(std::memory_order_acquire) 方法
*		做原子置位并返回 “旧值”(这里 “成功” 获取到后，返回的 “旧值” 为 0);
*	（3）在 unlock() 方法中，使用 flag.clear(std::memory_order_release) 方法，
*		做原子置位并返回 “旧值”(这里为 1);
*/
static void test6()
{
	atomic_flag lock = ATOMIC_FLAG_INIT;
	cout << "test6 first test_and_set = " << lock.test_and_set(std::memory_order_acquire) << endl;
	cout << "test6 second test_and_set = " << lock.test_and_set(std::memory_order_acquire) << endl;
	lock.clear(std::memory_order_release);
	cout << "test6 after clear = " << lock.test_and_set() << endl;
}

int main()
{
	// 总结：
	// 1. atomic用于无锁原子读写，适合计数、状态、标记等简单共享数据。
	// 2. load/store、fetch_add、exchange、CAS、atomic_flag是最常见的基础接口。
	// 3. CAS的关键是理解expected会回写、weak适合循环重试。
	// 4. atomic只保证单次操作原子，不自动保证多个步骤组成的业务逻辑安全。
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();

	return 0;
}