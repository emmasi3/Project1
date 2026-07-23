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

// ===================================================================
// test6_1: 讨论 "用户不指定内存序" 时自旋锁的行为与影响
// ===================================================================
// 背景：test6 中显式传递了 memory_order_acquire / memory_order_release。
//       如果用户不传内存序参数，test_and_set 和 clear 会使用默认参数
//       std::memory_order_seq_cst（顺序一致性）。
//
// 一、发现问题：默认内存序是什么？
//   - test_and_set() 默认参数是 std::memory_order_seq_cst。
//   - clear()       默认参数是 std::memory_order_seq_cst。
//   - 也就是说，用户不传任何参数时，全部操作都按最强内存序执行。
//
// 二、讨论问题：默认 seq_cst 能实现自旋锁吗？
//   （1）seq_cst 是 acquire/release 的超集。
//        - seq_cst 不仅包含 acquire 的 "后续指令不可上移" 语义，
//          也包含 release 的 "前序指令不可下移" 语义。
//        - 除此之外，seq_cst 还要求所有线程看到统一的全局操作顺序。
//   （2）因此，用默认 seq_cst 完全可以正确实现自旋锁的基本功能：
//        - 加锁：test_and_set() 原子置 true 并返回旧值，获取语义天然包含在内。
//        - 解锁：clear() 原子置 false，释放语义天然包含在内。
//        - 临界区同步：seq_cst 保证了 happens-before 关系，数据可见性没有问题。
//
// 三、解决问题：用默认 seq_cst 有什么影响？
//   （1）正确性：无影响。自旋锁功能完全正常。
//   （2）性能：有影响。
//        - 在 x86/x64 架构上，硬件本身内存模型较强，seq_cst 与 acquire/release
//          的指令差异很小，几乎感知不到。
//        - 在 ARM/PowerPC 等弱内存序架构上，seq_cst 会插入额外的内存屏障指令
//          （如 dmb、sync），比 acquire/release 多一次全局同步，开销更大。
//   （3）语义：过度约束。
//        - 自旋锁只需要成对的 acquire-release 即可保证临界区同步。
//        - seq_cst 额外要求 "所有线程看到统一全局顺序"，这对自旋锁是冗余的，
//          会增加编译器优化受限和硬件屏障增多的代价。
//
// 四、本测试案例演示：不传内存序 vs 传内存序
//   - step1: 用默认参数模拟自旋锁（功能正常）。
//   - step2: 对比 acquire/release 与 seq_cst 的行为差异。
//
// 五、总结经验：
//   （1）默认 seq_cst 能正确工作，功能上不存在任何问题。
//   （2）但自旋锁的最佳实践是：
//       加锁 → memory_order_acquire
//       解锁 → memory_order_release
//       这是 "刚好够用" 且性能最优的选择。
//   （3）规则：在能满足正确性的前提下，使用最弱的内存序。
//       acquire/release < seq_cst（从弱到强），能用前者就不要用后者。
//
// 六、注意事项：
//   （1）不要认为 "默认的就是最好的"——默认 seq_cst 是为了安全（不出错），
//       但不代表最优。
//   （2）单线程测试看不出性能差异，需要在多线程竞争场景下对比。
//   （3）如果只是学习/调试阶段，用默认 seq_cst 完全够用，不必纠结。
//   （4）如果是跨平台库，建议显式指定 acquire/release，确保在各架构上都有
//       最优表现。
//   （5）relaxed 内存序不能替代 acquire/release，因为它不保证任何顺序，
//       用在自旋锁上会导致临界区数据可见性问题。
// ===================================================================
static void test6_1()
{
	cout << "========== test6_1: 默认内存序(seq_cst) vs 显式 acquire/release ==========" << endl;

	// ---------- 步骤1：用默认内存序(seq_cst)模拟自旋锁 ----------
	cout << "\n--- 步骤1: 默认 seq_cst 模拟自旋锁 ---" << endl;
	{
		atomic_flag lock = ATOMIC_FLAG_INIT;

		// 第一次加锁：当前 flag 为 false，test_and_set 返回 false（旧值），加锁成功
		bool ret1 = lock.test_and_set(); // 默认 memory_order_seq_cst
		cout << "第1次 test_and_set(默认seq_cst) 返回旧值 = " << ret1
			<< " (0表示加锁成功, 1表示已被锁)" << endl;

		// 第二次加锁：flag 已为 true，test_and_set 返回 true，加锁失败
		bool ret2 = lock.test_and_set(); // 默认 memory_order_seq_cst
		cout << "第2次 test_and_set(默认seq_cst) 返回旧值 = " << ret2
			<< " (锁已被持有, 自旋锁中会在此忙等)" << endl;

		// 解锁：将 flag 置回 false
		lock.clear(); // 默认 memory_order_seq_cst
		cout << "clear(默认seq_cst) 释放锁" << endl;

		// 再次加锁：flag 已为 false，加锁成功
		bool ret3 = lock.test_and_set(); // 默认 memory_order_seq_cst
		cout << "clear后 test_and_set(默认seq_cst) 返回旧值 = " << ret3
			<< " (释放后可重新加锁)" << endl;

		lock.clear(); // 恢复初始状态
	}

	// ---------- 步骤2：对比 acquire/release 与 seq_cst ----------
	cout << "\n--- 步骤2: 显式 acquire/release 对比 ---" << endl;
	{
		atomic_flag lock1 = ATOMIC_FLAG_INIT;
		atomic_flag lock2 = ATOMIC_FLAG_INIT;

		// lock1: 使用 acquire/release
		lock1.test_and_set(memory_order_acquire);
		lock1.clear(memory_order_release);

		// lock2: 使用默认 seq_cst
		lock2.test_and_set(); // 等价于 memory_order_seq_cst
		lock2.clear();        // 等价于 memory_order_seq_cst

		cout << "lock1(acquire/release) 与 lock2(seq_cst) 功能行为一致" << endl;
		cout << "但 lock1 在弱内存序架构上性能更优" << endl;
	}

	// ---------- 步骤3：验证 happens-before 关系 ----------
	cout << "\n--- 步骤3: 验证 happens-before 关系 ---" << endl;
	{
		// 模拟场景：线程A写共享数据，线程B读共享数据
		// acquire/release 和 seq_cst 都能保证以下 happens-before 关系：
		//   线程A: shared = 42 → unlock(release)
		//   线程B: lock(acquire) → 读取 shared 一定看到 42
		//
		// 但如果用 relaxed（最弱内存序），则没有这个保证，
		// 线程B可能读到旧值。

		atomic_flag lock = ATOMIC_FLAG_INIT;

		// 模拟线程A的写操作
		int shared_data = 0; // 受自旋锁保护的共享数据
		lock.test_and_set(memory_order_acquire); // 获取锁
		shared_data = 42;                        // 临界区内写数据
		lock.clear(memory_order_release);        // 释放锁（release保证shared_data写入可见）

		// 模拟线程B的读操作
		lock.test_and_set(memory_order_acquire); // 获取锁（acquire保证能看到release前的写入）
		cout << "线程B读取 shared_data = " << shared_data
			<< " (acquire/release保证能看到42)" << endl;
		lock.clear(memory_order_release);

		// 同样用默认 seq_cst 也保证这一点
		shared_data = 0;
		lock.test_and_set(); // seq_cst 加锁
		shared_data = 99;
		lock.clear();        // seq_cst 解锁
		lock.test_and_set(); // seq_cst 加锁
		cout << "seq_cst下读取 shared_data = " << shared_data
			<< " (seq_cst同样保证能看到99)" << endl;
		lock.clear();
	}

	cout << "\n========== test6_1 总结 ==========" << endl;
	cout << "1. 不指定内存序 → 默认 seq_cst → 自旋锁功能完全正常" << endl;
	cout << "2. 影响：弱内存序架构上性能不如 acquire/release" << endl;
	cout << "3. 最佳实践：加锁用 acquire，解锁用 release" << endl;
	cout << "4. 禁用 relaxed 做自旋锁，它不保证临界区数据可见性" << endl;
	cout << "===================================" << endl;
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
	//test6();
	test6_1();

	return 0;
}