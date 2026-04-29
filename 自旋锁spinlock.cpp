#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>

/*
* 对于这个类的代码的解释，
* 1、使用atomic<boll> 不好吗？为什么要用 atomic_flag 呢？
*	明白一点：
*	（1）lock_free：它永远不需要系统内核的锁或挂起线程就能完成原子操作。atomic_flag 明确被C++标准指出，具有这个特点
*	（2）atomic<bool> 是一个通用类型，内存占比大，而 atomic_flag 是最轻量的类型，适合 spinlock 的使用场景
* 关键点：

不可分割：操作执行的过程中，其他 CPU 核心/线程看不到中间状态

无需系统调用：不会挂起线程，也不依赖操作系统提供的锁机制

保证最终性：至少有一个线程可以完成操作，不会完全被饥饿

2️⃣ 硬件如何保证原子性（常见例子）
a) 读-改-写原子操作

CPU 提供了专门指令，比如：

CPU 架构	原子指令例子	功能
x86 / x64	LOCK CMPXCHG	比较并交换（compare-and-swap）
ARM	LDREX/STREX	Load-Exclusive / Store-Exclusive
x86	XCHG	交换寄存器和内存，自动原子

直观理解：

CPU 在执行这些指令时，硬件保证这一条指令完成前，内存值不会被其他 CPU 修改

如果多个线程同时执行，CPU 会序列化硬件总线访问，保证只有一个线程成功更新

b) 内存屏障（Memory Barrier / Fence）

硬件原子指令通常和 内存屏障 配合使用：

屏障的作用：禁止 CPU / 编译器把操作重排

确保：

临界区内操作在拿锁后执行

unlock 前操作对其他线程可见

在 C++ 里，这就是 memory_order_acquire / memory_order_release

3️⃣ 举个例子

假设我们有一个 atomic_flag：

std::atomic_flag flag = ATOMIC_FLAG_INIT;

while(flag.test_and_set(std::memory_order_acquire));

硬件层面发生了什么

CPU 执行 test_and_set 原子指令

CPU 总线/缓存控制：

保证指令不可被中断

保证其他 CPU 核心看到的 flag 状态要么是旧值（false），要么是已设置（true），不会出现“半更新”的状态

返回旧值给线程

线程根据返回值决定是否进入临界区

这个操作完全在 CPU 层面完成，不需要操作系统介入
* 
* 
* 
* 
* 2、test_and_set()函数会在内部记录(bool a = flag)、修改(flag = true)、返回(return a)值，这三步是连续的，不可分割，其他线程
*	只能获得 最终的 flag 的状态
* 
* 3、参数： memory_order_acquire 和 memory_order_release 用来保证，
*	（1）这一步之后的代码（加锁范围内），都在 lock() 之后执行，因为 CPU 和 编译器(优化)可能重新排序代码
*	（2）这一步之前的代码（释放锁之前的范围内），都在 unlock() 之前执行，和（1）一样，避免重新排序
* 
* 4、总之，下面的说明中，也清楚的解释了，spinlock的核心思想：“自旋”，一直占用CPU，所以就省下了 CPU 上下文切换的消耗，
*	但是应用不当，极有可能造成：CPU 消耗过大的情况
* 
* 5、std::this_thread::yield(); 这句代码在这种轻量级的类中，可有可无，追求极致性能，安全全靠自己的话，不加这个，直接这样写就行了
* 
*/

class SpinLock
{
public:
	void lock()
	{
		while (flag.test_and_set(std::memory_order_acquire))
		{
			std::this_thread::yield();
		}
	}

	void unlock()
	{
		flag.clear(std::memory_order_release);
	}

private:
	SpinLock() = default;
	SpinLock(const SpinLock&) = delete;
	SpinLock& operator=(const SpinLock&) = delete;

private:
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

/*
* 
* 一、spinlock 简介
* 自旋锁（spinlock）：是指当一个线程在获取锁的时候，如果锁已经被其它线程获取，那么该线程将循环等待，不断尝试获取锁，直到获取到锁才会退出循环。
* 
* 二、自旋锁与互斥锁的区别
* 自旋锁与互斥锁类似，它们都是为了解决对某项资源的互斥使用，在任何时刻最多只能有一个线程获得锁。
* 
* 对于互斥锁，如果资源已经被占用，调用者将进入睡眠状态（CPU时间片主动放弃了，保存了上下文并切换）
* 对于自旋锁，如果资源已经被占用，调用者就一直循环在那里，看是否自旋锁的保持者已经释放了锁，（最简单的实现就是while()死循环）
* 
* 三、自旋锁的优缺点
* 1、自旋锁不会使线程状态发生切换，不会使线程进入阻塞状态，减少了不必要的上下文切换，执行速度快。
* 、非自旋锁在获取不到锁的时候会进入阻塞状态，从而进入内核态，当获取到锁的时候需要从内核态恢复，需要线程上下文切换，影响性能。
* 2、如果某个线程持有锁的时间过长，就会导致其它等待获取锁的线程长时间循环等待消耗CPU，造成CPU使用率极高。
* 
*/

int main()
{
	

	return 0;
}