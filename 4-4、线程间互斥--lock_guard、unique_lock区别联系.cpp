#include <iostream>
#include <string>
#include <mutex>
#include <atomic>
#include <functional>
#include <memory>
#include <thread>
#include <vector>
#include <chrono>

// 测试 1: lock_guard 基本用法
// 测试目的：演示 std::lock_guard 的 RAII 特性——在构造时加锁，析构时解锁，无法手动 unlock，适合简单作用域锁定场景
static void test_lock_guard_basic()
{
	std::mutex m;
	int counter = 0;

	auto worker = [&m, &counter]() {
		for (int i = 0; i < 1000; ++i) {
			std::lock_guard<std::mutex> g(m);
			++counter;
		}
	};

	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i) threads.emplace_back(worker);
	for (auto &t : threads) t.join();

	std::cout << "test_lock_guard_basic: counter = " << counter << " (expected 10000)\n";
}

// 测试 2: lock_guard 遇到异常时的释放（作用域级别的自动解锁）
// 测试目的：演示 lock_guard 在异常抛出时 "也" 会在析构时释放锁
static void test_lock_guard_exception()
{
	std::mutex m;
	bool unlocked_after_exception = false;

	try {
		std::lock_guard<std::mutex> g(m);
		throw std::runtime_error("simulate error");
	}
	catch (...) {
		// 如果 lock_guard 在异常时没有释放锁，则下面 try_lock 将失败
		if (m.try_lock()) {
			unlocked_after_exception = true;
			m.unlock();
		}
	}

	std::cout << "test_lock_guard_exception: unlocked_after_exception = " << std::boolalpha << unlocked_after_exception << "\n";
}

// 测试 3: unique_lock 的 defer_lock 与 try_lock
// 测试目的：演示 std::unique_lock 更灵活：可以延迟加锁、尝试加锁、手动 unlock
static void test_unique_lock_defer_try()
{
	std::mutex m;
	bool try_succeeded = false;

	std::unique_lock<std::mutex> lk(m, std::defer_lock); // 不在构造时加锁
	// 手动加锁
	lk.lock();
	// 手动解锁
	lk.unlock();

	// 再次尝试加锁（非阻塞）
	if (lk.try_lock()) {
		try_succeeded = true;
		lk.unlock();
	}

	std::cout << "test_unique_lock_defer_try: try_succeeded = " << std::boolalpha << try_succeeded << "\n";
}

// 测试 4: unique_lock 的 release 和 adopt_lock
// 测试目的：演示 release 将所有权交出但不解锁，调用者需自行处理；adopt_lock 表示接受已加锁的 mutex
static void test_unique_lock_release_adopt()
{
	std::mutex m;
	m.lock(); // 手动加锁
	{
		// adopt_lock 表示 unique_lock 接管已经加锁的 mutex，不会再次加锁
		std::unique_lock<std::mutex> lk(m, std::adopt_lock);
		// 现在我们故意释放所有权，但 mutex 仍然被锁着
		std::mutex* raw = lk.release(); // lk 不再负责解锁
		// 手动解锁
		raw->unlock();
	}

	// 如果上面没有手动解锁，这里尝试加锁会死锁或失败；我们已经解锁，所以可以成功
	bool locked = false;
	if (m.try_lock()) {
		locked = true;
		m.unlock();
	}

	std::cout << "test_unique_lock_release_adopt: locked = " << std::boolalpha << locked << "\n";
}

// 测试 5: unique_lock 的可移动性 vs lock_guard 不可移动
// 测试目的：演示 unique_lock 可移动（支持转移所有权），而 lock_guard 是不可移动的（不能赋值或移动）
static void test_unique_lock_move()
{
	std::mutex m;
	std::unique_lock<std::mutex> a(m); // a 持有锁
	std::unique_lock<std::mutex> b = std::move(a); // 将所有权移动到 b
	// 当前 unique_lock 对象是否拥有互斥锁的所有权
	bool a_owns = a.owns_lock();
	bool b_owns = b.owns_lock();

	std::cout << "test_unique_lock_move: a_owns = " << std::boolalpha << a_owns << ", b_owns = " << b_owns << "\n";

	// 注意：下面这行如果取消注释将无法编译，因为 std::lock_guard 不可移动
	// std::lock_guard<std::mutex> lg1(m);
	// std::lock_guard<std::mutex> lg2 = std::move(lg1); // error: lock_guard is non-movable
}

int main()
{
	//test_lock_guard_basic();
	//test_lock_guard_exception();
	//test_unique_lock_defer_try();
	//test_unique_lock_release_adopt();
	test_unique_lock_move();

	// 总结要点：
	std::cout << "\n总结：\n";
	std::cout << "1) std::lock_guard: 简单、轻量、RAII，在构造时加锁、析构时解锁；不可手动 unlock；不可移动；适合作用域内简单保护。\n";
	std::cout << "2) std::unique_lock: 更加灵活，支持 defer_lock(延迟加锁)、try_lock(尝试加锁)、adopt_lock(接管已加锁的 mutex)、release(放弃所有权但不解锁)、可移动；适合需要更复杂控制或与 condition_variable 一起使用。\n";
	std::cout << "3) 性能：lock_guard 通常比 unique_lock 更轻量，若不需要可选特性优先使用 lock_guard。\n";
	std::cout << "4) 当需要可变的锁所有权、延迟加锁或与条件变量配合使用时，选择 unique_lock。\n";

	return 0;
}
