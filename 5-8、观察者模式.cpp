#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <mutex>
#include <string>

// 观察者模式示例集合：每个静态方法为一个小测试，展示一个知识点、遇到的问题、解决思路与注意事项。

// 被观察者（Subject） - 推/拉混合实现
class Subject {
public:
	using StateType = int;

	void SetState(StateType s) {
		std::lock_guard<std::mutex> lk(m_);
		state_ = s;
	}

	StateType GetState() const {
		return state_;
	}

	// 订阅：观察者用 shared_ptr 传入，Subject 内部用 weak_ptr 存储以免循环引用
	typedef std::function<void(StateType)> Callback;

	void Attach(const std::shared_ptr<Callback>& cb) {
		std::lock_guard<std::mutex> lk(m_);
		callbacks_.push_back(cb);
	}

	void DetachExpired() {
		std::lock_guard<std::mutex> lk(m_);
		callbacks_.erase(std::remove_if(callbacks_.begin(), callbacks_.end(), [](const std::shared_ptr<Callback>& p) {
			return p == nullptr;
		}), callbacks_.end());
	}

	// Notify - 推模型：传递状态给回调
	void NotifyPush() {
		std::vector<std::shared_ptr<Callback>> copy;
		{
			std::lock_guard<std::mutex> lk(m_);
			copy = callbacks_; // 复制一份，避免回调中修改订阅列表导致迭代器失效
		}
		for (auto &cb : copy) {
			if (cb) 
				(*cb)(state_);
		}
	}

	// Notify - 拉模型：回调仅提醒，观察者自己到 Subject 拉取数据
	void NotifyPull() {
		std::vector<std::shared_ptr<Callback>> copy;
		{
			std::lock_guard<std::mutex> lk(m_);
			copy = callbacks_;
		}
		for (auto &cb : copy) {
			if (cb) 
				(*cb)((StateType)0); // 约定：参数不代表状态，观察者将调用 GetState()
		}
	}

private:
	mutable std::mutex m_;
	StateType state_{0};
	std::vector<std::shared_ptr<Callback>> callbacks_; // 存 shared_ptr 以便简单管理生命周期
};

struct ObserverTests {
	/*
	Test1：基本观察者注册与通知（推模型）
	知识点：观察者通过回调形式注册，被观察者在状态改变时主动推送新状态。
	问题：如何在不耦合具体类的情况下通知多方？
	思路：被观察者维护回调列表，状态变化时逐个调用回调。
	注意：回调执行期间可能修改订阅列表，故需复制回调列表后再调用。
	*/
	static void Test1_BasicPush() {
		std::cout << "----Test1_BasicPush----" << std::endl;
		Subject s;
		s.SetState(42);

		auto cb = std::make_shared<Subject::Callback>([&](Subject::StateType st){
			std::cout << "Observer received state (push): " << st << std::endl;
		});
		s.Attach(cb);
		s.NotifyPush();
	}

	/*
	Test2：拉模型（Pull）示例
	知识点：观察者仅收到通知，主动向 Subject 拉取需要的数据。
	问题：当状态较大或频繁变化，推模型可能效率低或不适用？
	思路：在回调里观察者调用 Subject::GetState() 拉取当前数据。
	注意：拉模型需要观察者持有 Subject 引用或按其它手段访问状态。
	*/
	static void Test2_PullModel() {
		std::cout << "----Test2_PullModel----" << std::endl;
		auto subjectPtr = std::make_shared<Subject>();
		subjectPtr->SetState(100);

		// 观察者持有 subject 的弱引用并在回调中拉取状态
		auto weakSub = std::weak_ptr<Subject>(subjectPtr);
		auto cb = std::make_shared<Subject::Callback>([weakSub](Subject::StateType){
			if (auto spt = weakSub.lock()) {
				std::cout << "Observer pulls state: " << spt->GetState() << std::endl;
			} else {
				std::cout << "Subject expired" << std::endl;
			}
		});
		subjectPtr->Attach(cb);
		subjectPtr->NotifyPull();
	}

	/*
	Test3：观察者生命周期管理（使用弱引用避免悬挂）
	知识点：观察者可能被销毁但忘记注销，若 Subject 保持强引用会导致悬挂或内存泄漏。
	问题：如何优雅处理观察者被销毁而不显式 Detach 的情况？
	思路：Subject 存储弱引用或 shared_ptr 回调，定期清理已过期回调；观察者使用 shared_ptr 管理自己。
	注意：本示例使用 shared_ptr 回调并在 Notify 前复制，真实系统可改为 weak_ptr 存储并在调用前 lock。
	*/
	static void Test3_LifetimeManagement() {
		std::cout << "----Test3_LifetimeManagement----" << std::endl;
		Subject s;

	auto cbHolder = std::make_shared<Subject::Callback>([](Subject::StateType st){
			std::cout << "Ephemeral observer saw: " << st << std::endl;
		});
		{
			// 模拟观察者作用域结束后自动释放回调对象
			s.Attach(cbHolder);
		}
		// 此时 cbHolder 仍有 shared_ptr（由 Attach 时复制），要模拟自动失效需手动置空或支持过期检测
		// 为简洁，演示 DetachExpired() 清理空指针（示例有限）
		cbHolder.reset();
		s.DetachExpired();
		s.SetState(7);
		s.NotifyPush();
	}

	/*
	Test4：观察者在通知期间取消订阅（安全取消）
	知识点：回调中可能执行 Detach，若直接遍历原列表会破坏迭代器。
	问题：如何在回调允许修改订阅列表仍保证安全？
	思路：在 Notify 时复制回调列表并对副本进行迭代；对原列表的修改不会影响当前通知流程。
	注意：复制会有性能开销，适用于中等规模；高频场景需设计更高效的数据结构或延迟变更应用。
	*/
	static void Test4_DetachDuringNotify() {
		std::cout << "----Test4_DetachDuringNotify----" << std::endl;
		Subject s;
		auto cb1 = std::make_shared<Subject::Callback>([&](Subject::StateType st){
			std::cout << "Observer1 got: " << st << std::endl;
		});
		auto cb2 = std::make_shared<Subject::Callback>([&](Subject::StateType st){
			std::cout << "Observer2 got and will detach itself" << std::endl;
			// 模拟在回调中清空所有回调（可能来自某个观察者想取消订阅）
			// 这里直接演示：通过 dropping cb1/cb2 本地副本，真实场景需要 Subject 提供 Detach 接口
		});
		s.Attach(cb1);
		s.Attach(cb2);
		s.SetState(3);
		// NotifyPush 复制列表后调用，内部的修改不会干扰当前遍历
		s.NotifyPush();
	}

	/*
	Test5：事件过滤（有条件地接收通知）
	知识点：有时观察者只对某类事件感兴趣，可在回调前加过滤器。
	问题：如何避免每个回调都被无关事件触发？
	思路：将过滤逻辑封装到回调闭包中或在 Subject 支持带条件的订阅。
	注意：把过滤逻辑放在观察者侧可保持 Subject 简洁；Subject 也可支持注册带 predicate 的回调。
	*/
	static void Test5_EventFiltering() {
		std::cout << "----Test5_EventFiltering----" << std::endl;
		Subject s;
		s.SetState(10);
		auto interestedInEven = std::make_shared<Subject::Callback>([](Subject::StateType st){
			if (st % 2 == 0) std::cout << "Even observer got: " << st << std::endl;
		});
		s.Attach(interestedInEven);
		s.NotifyPush();
	}

	/*
	Test6：线程安全提醒（示例加锁）
	知识点：多线程下 Subject 的订阅/通知需同步。
	问题：并发订阅、退订或通知会导致竞态和崩溃。
	思路：在 Subject 内使用互斥量保护数据结构；通知时复制回调列表以降低锁持有时间。
	注意：复杂并发场景建议使用并发队列或事件分发线程，不要长时间在锁内执行回调。
	*/
	static void Test6_ThreadSafetyNote() {
		std::cout << "----Test6_ThreadSafetyNote----" << std::endl;
		// 通过 Subject 的实现已经演示了基本互斥保护
		Subject s;
		auto cb = std::make_shared<Subject::Callback>([](Subject::StateType st){
			std::cout << "Thread-safe callback sees: " << st << std::endl;
		});
		s.Attach(cb);
		s.SetState(99);
		s.NotifyPush();
	}
};

int main() {
	ObserverTests::Test1_BasicPush();
	std::cout << std::endl;

	ObserverTests::Test2_PullModel();
	std::cout << std::endl;

	//ObserverTests::Test3_LifetimeManagement();
	//std::cout << std::endl;

	//ObserverTests::Test4_DetachDuringNotify();
	//std::cout << std::endl;

	//ObserverTests::Test5_EventFiltering();
	//std::cout << std::endl;

	//ObserverTests::Test6_ThreadSafetyNote();
	//std::cout << std::endl;

	// ========== 总结 ==========
	// 1) 观察者模式核心：定义一对多依赖，被观察者状态变化时通知多个观察者。
	// 2) 推 vs 拉：推模型由 Subject 主动发送数据；拉模型通知后观察者主动获取数据。
	// 3) 生命周期：避免循环引用，建议 Subject 存弱引用或以回调形式存储并清理过期项。
	// 4) 安全性：通知时复制回调列表以允许回调中安全修改订阅集合；通知应尽量缩短锁持有时间。
	// 5) 并发：多线程场景需同步订阅/退订/通知，复杂场景建议事件队列或专用发布线程。
	// 6) 变体与扩展：支持过滤、优先级、批量通知、异步分发等。

	return 0;
}
