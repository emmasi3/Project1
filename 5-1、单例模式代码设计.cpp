#include <iostream>
#include <string>
#include <memory>

/*
* @brief 这是一个 “线程安全” 的 “懒汉单例模式”，只有在第一次调用到他时，才初始化对象
* 
* @note	而 “饿汉模式” 是在 main() 开始之前，他就已经存在到全局区内存的数据段上了
*		所以在这种模式下，初始化过程是 “线程安全” 的
*/
template<class T>
class Singleton
{
public:
	Singleton() = delete;
	Singleton(const Singleton&) = delete;
	Singleton(const Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(const Singleton&&) = delete;

	static T* GetInstance()
	{
		static T instance;
		return &instance;
	}

	// 以下这两种方式是不可行的，如果使用 “智能指针” 接管对象，那么全局唯一实例
	// 的声明周期大概率不会持续到程序结束，析构后，别的地方调用该方法，就会错误，
	// 因为调用了 delete，释放了资源，所以不能够在 "堆" 上创建对象，而是应该
	// 使用 static T instance; 局部静态变量，编译器保证只会初始化一次(初始化过程线程安全)
	// 并且 全局区的内存由系统管理，不需要手动释放
	// 
	//static std::shared_ptr<T> GetInstance_shared()
	//{
	//	static std::shared_ptr<T> ptr(new T);
	//	return ptr;
	//}

	//static std::unique_ptr<T> GetInstance_unique()
	//{
	//	static std::unique_ptr<T> ptr(new T);
	//	return ptr;
	//}

private:

};


class LoggerMgr
{
public:
	typedef std::unique_ptr<LoggerMgr> ptr;

private:

};

typedef Singleton<LoggerMgr> LMG;


static void test1()
{
	//LoggerMgr::ptr ptr(LMG::GetInstance());
	////LoggerMgr::ptr ptr = std::make_unique<LoggerMgr>(LMG::GetInstance());
	//std::cout << "LoggerMgr::ptr ptr = std::make_unique<LoggerMgr>(LMG::GetInstance());"
	//	" &ptr = " << ptr << '\n';
	//LMG::GetInstance();

	LoggerMgr* ptr = LMG::GetInstance();
	std::cout << ptr << '\n';
}

int main()
{
	test1();

	return 0;
}