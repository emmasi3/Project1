#include <iostream>
#include <memory>

/*
* @brief auto_ptr 的一些问题
*/
static void test1()
{
	// std::auto_ptr 好像被弃用了，从 C++17
	/*
	* 1、这就是一个没有引用计数的智能指针
	*	auto_ptr<int> ptr1(new int);
	*	auto_ptr<int> ptr2(ptr1);
	*	第二句代码触发了拷贝构造，(const auto_ptr<int>& src);
	*	_Tx* tx = src->ptr;
	*	src->ptr = nullptr;
	*	return tx;
	*	大概就是这样子的一个 “移动语义”
	*	但是如果开发者不太熟悉这玩意，就会认为 ptr1 在拷贝构造之后还持有之前的 new int 内存
	*	这个看起来并不是不能用是吧？但是对于一个常见的场景：
	*	使用 std::vector<std::auto_ptr<T>> vec;
	*	如果这个 vector 要进行拷贝，那么其中的所有auto_ptr，都会调用内部的拷贝构造
	*	底层指针都会被置为 nullptr; 这需要你去做额外的很多事，不方便
	*	既然是为了方便开发者使用，这样的一个 “无引用的智能指针” 肯定是不合格的
	*	
	*/
}

/*
* @brief scoped_ptr
*/
static void test2()
{
	/*
	* 这玩意好像也被弃用了？
	* 1、这个东西在 auto_ptr 的基础上，做了一些调整
	* 
	*	为了避免上面的 auto_ptr 在拷贝构造后，需要手动调整的一些繁琐的问题，
	*	C++标准库中，直接这样做：
	*	scoped_ptr(const scoped_ptr<T>&) = delete;
	*	scoped_ptr<T>& operator=(const scoped_ptr<T>&) = delete;
	*	直接不让你用拷贝，这份资源不能够共享，哎~ 这样看起来也达不到 智能指针的 “智能” 语义
	*   所以 C++标准中，不推荐使用
	* 
	* 2、他好像也不支持 “移动”？应该将对应的放 = delete; 了
	*/
}

/*
* @brief unique_ptr -- 独享指针 -- 无引用计数
*/
static void test3()
{
	std::unique_ptr<int> ptr1(new int(5));
	std::cout << *ptr1 << '\n';

	std::unique_ptr<int> ptr2(std::move(ptr1));
	// 修改值
	*ptr2 = 15;
	std::cout << *ptr2 << '\n';

	/*
	* 1、C++标准推荐使用的 unique_ptr 和上面的 scoped_ptr 有什么区别呢？
	*	为什么推荐？
	*	（1）首先，它拥有完善的资源释放机制，这是最基本的，他们三都有
	*	（2）和 scoped_ptr 一样，unique_ptr 由于语义上的 “独享”
	*		直接 delete 了 “拷贝构造” 和 “拷贝赋值运算符”
	*	（3）unique_ptr 拥有 “移动构造” 和 “移动赋值运算符”，从而拥有的了 “移动语义”
	*	这就让开发者使用 unique_ptr 时，有着清晰的语义支撑，使用起来也更加顺手
	*	
	*	std::unique_ptr<int> ptr2(std::move(ptr1));
	*	显式地 “转移” 了 ptr1 只有的资源所有权，给到了 ptr2
	*	“语义” 和 “目的” 都达成了，还有这自动管理资源的功能，这才够格被称为
	*	“不带引用计数的智能指针”
	* 
	*/
}

int main()
{
	test1();

	test2();

	test3();

	return 0;
}
