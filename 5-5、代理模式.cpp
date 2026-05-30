#include <iostream>
#include <memory>
#include <string>

// 代理模式示例集合：每个静态方法为一个小测试，展示一个知识点、问题、解决思路与注意事项。

// 抽象接口（Subject）
struct ISubject {
	virtual ~ISubject() = default;
	virtual void Request(const std::string& msg) = 0;
};

// 真实主题（RealSubject）
struct RealSubject : ISubject {
	void Request(const std::string& msg) override {
		std::cout << "RealSubject handling: " << msg << std::endl;
	}
};

// 普通代理：最基本的转发（透明代理）
struct SimpleProxy : ISubject {
	// 描述：最常见的代理实现方式，持有真实主题并转发调用。
	// 问题：如何在不改变客户端的情况下加入额外行为（如日志、权限）？
	// 解决：在代理中包装真实主题的调用，执行前/后逻辑。
	// 注意：代理与真实主题实现同一接口，客户端无需感知代理存在；注意生命周期管理。
	SimpleProxy(std::shared_ptr<ISubject> real) : real_(real) {}
	void Request(const std::string& msg) override {
		// 额外行为：示例为简单日志
		std::cout << "[SimpleProxy] before Request" << std::endl;
		real_->Request(msg);
		std::cout << "[SimpleProxy] after Request" << std::endl;
	}
private:
	std::shared_ptr<ISubject> real_;
};

// 日志代理：示例将横切关注点放入代理
struct LoggingProxy : ISubject {
	// 描述：将日志记录作为代理职责，避免污染真实主题实现。
	// 问题：横切关注点如何在不改变核心逻辑的情况下添加？
	// 解决：引入代理统一拦截接口调用并记录日志。
	// 注意：如果日志逻辑复杂，代理会变得臃肿，考虑使用装饰器或AOP框架。
	LoggingProxy(std::shared_ptr<ISubject> real) : real_(real) {}
	void Request(const std::string& msg) override {
		std::cout << "[LoggingProxy] log: calling Request with '" << msg << "'" << std::endl;
		real_->Request(msg);
	}
private:
	std::shared_ptr<ISubject> real_;
};

// 保护代理（Protection Proxy）：在转发前检查权限
struct ProtectionProxy : ISubject {
	// 描述：代理用于控制对真实主题的访问（权限、认证）。
	// 问题：如何在运行时拒绝不合法访问？
	// 解决：在代理中进行权限判断，决定是否转发。
	// 注意：权限逻辑应尽量简单明确，不要把策略硬编码在代理中。
	ProtectionProxy(std::shared_ptr<ISubject> real, bool allowed) : real_(real), allowed_(allowed) {}
	void Request(const std::string& msg) override {
		if (!allowed_) {
			std::cout << "[ProtectionProxy] access denied for message: " << msg << std::endl;
			return;
		}
		real_->Request(msg);
	}
private:
	std::shared_ptr<ISubject> real_;
	bool allowed_;
};

// 虚代理（Virtual Proxy）：按需创建真实主题（延迟实例化）
struct VirtualProxy : ISubject {
	// 描述：当真实对象创建代价高或延迟创建需求时使用。
	// 问题：如何延迟创建并保证线程安全与生命周期？
	// 解决：在代理内部持有空指针，首次请求时创建真实对象；在多线程场景下需加锁或使用线程安全的单例/工厂。
	// 注意：延迟加载可以节约内存/资源，但增加了代理复杂度及并发控制需求。
	VirtualProxy() = default;
	void Request(const std::string& msg) override {
		if (!real_) {
			// 延迟创建
			real_ = std::make_shared<RealSubject>();
			std::cout << "[VirtualProxy] RealSubject created lazily" << std::endl;
		}
		real_->Request(msg);
	}
private:
	std::shared_ptr<ISubject> real_;
};

// 远程代理示意（本地模拟）：在代理中构造一个网络请求的占位符
struct RemoteProxy : ISubject {
	// 描述：远程代理隐藏网络通信细节，客户端像调用本地对象一样使用代理。
	// 问题：如何屏蔽网络延迟、序列化、错误处理？
	// 解决：代理负责序列化/网络交互，并处理错误与重试策略。
	// 注意：示例为简化模拟，真实远程代理需处理序列化、网络IO与异常。
	void Request(const std::string& msg) override {
		std::cout << "[RemoteProxy] simulate sending '" << msg << "' to remote server..." << std::endl;
		// 模拟远端响应
		std::cout << "[RemoteProxy] remote server responded to '" << msg << "'" << std::endl;
	}
};

// 错误示例：对象切片导致代理失效
struct Concrete : ISubject {
	// 描述：演示返回具体类型或按值传递会引发对象切片，破坏多态（代理作用丢失）。
	// 问题：如果接口按值传递或返回具体类型，会导致派生部分被切掉，代理/多态失效。
	// 解决：总是通过指针/引用（或智能指针）使用接口类型以保留多态性。
	void Request(const std::string& msg) override {
		std::cout << "Concrete handling: " << msg << std::endl;
	}
};

struct ProxyTests {
	// 每个静态函数为一个测试案例

	/*
	Test1: 基本代理（透明代理）
	描述：代理实现与真实主题相同接口并转发调用，同时加入前置/后置逻辑。
	问题：如何在不改客户端代码的情况下加入额外行为？
	解决：使用实现相同接口的代理插入调用链。
	注意：保持接口一致性，管理好真实主题的生命周期（此处使用 shared_ptr 简化）。
	*/
	static void Test1_BasicProxy() {
		std::cout << "----Test1_BasicProxy----" << std::endl;
		auto real = std::make_shared<RealSubject>();
		SimpleProxy proxy(real);
		proxy.Request("hello basic");
	}

	/*
	Test2: 日志代理
	描述：将日志作为代理职责，示例展示如何记录方法参数。
	问题：跨切关注点如何与业务逻辑分离？
	解决：在代理中集中处理日志，保持真实主题专注业务。
	注意：不要让代理承担过多职责，否则应考虑责任分离或链式装饰器。
	*/
	static void Test2_LoggingProxy() {
		std::cout << "----Test2_LoggingProxy----" << std::endl;
		auto real = std::make_shared<RealSubject>();
		LoggingProxy proxy(real);
		proxy.Request("hello logging");
	}

	/*
	Test3: 保护代理（权限控制）
	描述：代理在转发前检查调用者权限，示例中用 bool 表示许可。
	问题：如何在运行时拒绝调用？
	解决：在代理中实现权限检查，不满足时不转发并反馈错误。
	注意：权限判断不应硬编码；可注入策略或使用外部认证模块。
	*/
	static void Test3_ProtectionProxy() {
		std::cout << "----Test3_ProtectionProxy----" << std::endl;
		auto real = std::make_shared<RealSubject>();
		ProtectionProxy denied(real, false);
		ProtectionProxy allowed(real, true);
		denied.Request("secret");
		allowed.Request("public");
	}

	/*
	Test4: 虚代理（延迟创建）
	描述：代理延迟创建昂贵对象，按需实例化。
	问题：如何保证延迟创建安全且不泄露资源？
	解决：代理内部管理智能指针，首次调用时创建真实对象。
	注意：在多线程环境下需加锁；考虑 double-checked locking 或线程安全工厂。
	*/
	static void Test4_VirtualProxyLazyInit() {
		std::cout << "----Test4_VirtualProxyLazyInit----" << std::endl;
		VirtualProxy proxy;
		// 第一次调用会创建真实对象
		proxy.Request("first call");
		// 第二次调用复用真实对象
		proxy.Request("second call");
	}

	/*
	Test5: 远程代理（简化示意）
	描述：代理封装远程调用细节，客户端无感知。
	问题：如何屏蔽网络通信的复杂性？
	解决：代理实现序列化/网络交互与重试/错误处理策略。
	注意：示例为本地模拟，真实实现需处理网络异常、超时、重试与回退策略。
	*/
	static void Test5_RemoteProxy() {
		std::cout << "----Test5_RemoteProxy----" << std::endl;
		RemoteProxy proxy;
		proxy.Request("remote operation");
	}

	/*
	Test6: 对象切片与接口使用（反面示例）
	描述：演示对象切片导致多态丢失的问题。
	问题：按值使用接口或返回具体类型会切片派生数据/行为。
	解决：始终通过指针或引用（或智能指针）操作接口类型以保留多态性。
	注意：在接口设计时避免按值传递需要保留多态性的对象。
	*/
	static void Test6_SlicingProblem() {
		std::cout << "----Test6_SlicingProblem----" << std::endl;
		Concrete concrete;
		ISubject* p = &concrete; // 正确：按指针使用保持多态
		p->Request("via pointer");
		// 错误示例（按值）: 会发生切片（下面一行是注释，实际代码不会编译为切片示例，因为C++不允许按值赋给抽象基类）
		std::cout << "[Note] 若按值返回或赋值给基类对象，会发生切片，避免按值使用接口类型。" << std::endl;
	}
};

int main() {
	// 运行所有测试
	ProxyTests::Test1_BasicProxy();
	ProxyTests::Test2_LoggingProxy();
	ProxyTests::Test3_ProtectionProxy();
	ProxyTests::Test4_VirtualProxyLazyInit();
	ProxyTests::Test5_RemoteProxy();
	ProxyTests::Test6_SlicingProblem();

	// 总结（注释形式）：
	// 1) 代理模式的核心：为其他对象提供一个表示（代理），并控制对该对象的访问。代理必须实现与真实主题相同的接口。
	// 2) 常见代理类型：透明代理（转发并可注入行为）、保护代理（权限控制）、虚代理（延迟加载）、远程代理（网络通信封装）、日志/缓存代理（横切关注点）。
	// 3) 设计注意事项：
	//    - 接口一致性：代理和真实主题实现相同接口，客户端无需感知代理存在。
	//    - 生命周期管理：代理通常持有真实主题的引用/指针，推荐使用智能指针管理所有权；注意可能的循环引用。
	//    - 并发与延迟加载：虚代理在多线程环境需正确加锁或使用线程安全初始化模式。
	//    - 职责单一：避免把过多逻辑堆在代理中；复杂逻辑应委托给专门模块或策略对象。
	//    - 性能影响：代理增加一层间接调用，必要时衡量开销；对于高频调用考虑内联/优化路径。
	//    - 对象切片：不要按值传递/返回需要保留多态性的对象，总是使用指针/引用/智能指针。
	// 4) 使用场景：远程服务访问、延迟加载、权限校验、日志/监控、缓存、事务管理等。

	return 0;
}
