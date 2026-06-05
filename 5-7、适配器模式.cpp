#include <iostream>
#include <string>
#include <memory>

// 适配器模式示例集合：每个静态方法都是一个小测试，分别体现一个知识点、
// 一个常见问题、对应解决思路和注意事项。

// ============= 目标接口 =============
// USB 接口（客户端期望的新接口）
struct IUSBPort {
	virtual ~IUSBPort() = default;
	virtual std::string GetType() const = 0;
	virtual void Charge() = 0;
	virtual void TransferData(const std::string& data) = 0;
};

// ============= 老旧接口 =============
// 并口接口（需要适配的旧接口）
struct ParallelPort {
	virtual ~ParallelPort() = default;
	virtual std::string GetPortType() const {
		return "ParallelPort";
	}

	virtual void SendData(const std::string& data) {
		std::cout << "ParallelPort sending: " << data << std::endl;
	}
};

// 串口接口（另一个旧接口）
struct SerialPort {
	virtual ~SerialPort() = default;
	virtual std::string Describe() const {
		return "SerialPort";
	}

	virtual void Write(const std::string& data) {
		std::cout << "SerialPort writing: " << data << std::endl;
	}
};

// ============= 对象适配器（推荐：组合方式） =============
// 并口 -> USB 适配器
struct ParallelToUSBAdapter : IUSBPort {
	explicit ParallelToUSBAdapter(std::shared_ptr<ParallelPort> port)
		: port_(std::move(port)) {}

	std::string GetType() const override {
		return "USB-" + port_->GetPortType();
	}

	void Charge() override {
		std::cout << "Adapter: Charging via " << port_->GetPortType() << std::endl;
	}

	void TransferData(const std::string& data) override {
		// 适配接口：将 USB 的 TransferData 适配为 ParallelPort 的 SendData
		port_->SendData(data);
	}

private:
	std::shared_ptr<ParallelPort> port_;
};

// 串口 -> USB 适配器
struct SerialToUSBAdapter : IUSBPort {
	explicit SerialToUSBAdapter(std::shared_ptr<SerialPort> port)
		: port_(std::move(port)) {}

	std::string GetType() const override {
		return "USB-" + port_->Describe();
	}

	void Charge() override {
		std::cout << "Adapter: Charging via " << port_->Describe() << std::endl;
	}

	void TransferData(const std::string& data) override {
		// 适配接口：将 USB 的 TransferData 适配为 SerialPort 的 Write
		port_->Write(data);
	}

private:
	std::shared_ptr<SerialPort> port_;
};

// ============= 类适配器（多继承方式，C++特有） =============
struct LegacyParallelPort : ParallelPort {
	void SendData(const std::string& data) override {
		std::cout << "LegacyParallelPort: " << data << std::endl;
	}
};

struct ClassBasedAdapter : LegacyParallelPort, IUSBPort {
	std::string GetType() const override {
		return "USB-ClassAdapter";
	}

	void Charge() override {
		std::cout << "ClassAdapter: Charging" << std::endl;
	}

	void TransferData(const std::string& data) override {
		SendData(data);  // 直接调用继承的方法
	}
};

struct AdapterTests {
	/*
	Test1：对象不兼容的问题描述。
	知识点：客户端期望 USB 接口，但拿到的是旧的并口或串口。
	问题：无法直接使用旧接口，不改旧代码怎么办？
	思路：创建一个适配器，实现新接口，内部调用旧接口。
	注意：适配器本身不改变旧对象的行为，只是提供一个新的"门面"。
	*/
	static void Test1_BasicIncompatibility() {
		std::cout << "----Test1_BasicIncompatibility----" << std::endl;
		auto oldPort = std::make_shared<ParallelPort>();
		// 客户端需要 USB 接口，但只有 oldPort
		// 如果直接用 IUSBPort* p = oldPort; 会编译错误
		// 解决办法：用适配器包装
		std::shared_ptr<IUSBPort> usbPort = 
			std::make_shared<ParallelToUSBAdapter>(oldPort);
		usbPort->TransferData("Hello from Adapter");
	}

	/*
	Test2：对象适配器与类适配器的对比。
	知识点：对象适配器用组合，类适配器用多继承。
	问题：用哪一个？有什么区别？
	思路：对象适配器更灵活、更符合组合优先的设计原则。
		  类适配器侵入式，但有时代码更简洁。
	注意：优先选对象适配器；多继承要小心菱形问题。
	*/
	static void Test2_ObjectVsClassAdapter() {
		std::cout << "----Test2_ObjectVsClassAdapter----" << std::endl;
		// 对象适配器
		auto parallelPort = std::make_shared<ParallelPort>();
		std::shared_ptr<IUSBPort> objectAdapter = 
			std::make_shared<ParallelToUSBAdapter>(parallelPort);
		std::cout << "Object Adapter: " << objectAdapter->GetType() << std::endl;

		// 类适配器
		auto classAdapter = std::make_shared<ClassBasedAdapter>();
		std::cout << "Class Adapter: " << classAdapter->GetType() << std::endl;
	}

	/*
	Test3：多个不同旧接口的适配。
	知识点：单个适配器可以适配一种旧接口，多接口需要多个适配器。
	问题：系统中有多种旧接口，怎么统一到新接口？
	思路：为每种旧接口各写一个适配器，都实现新接口。
	注意：适配器数量会随旧接口数增加而增加，保持代码组织清晰。
	*/
	static void Test3_AdaptMultipleInterfaces() {
		std::cout << "----Test3_AdaptMultipleInterfaces----" << std::endl;
		auto parallelPort = std::make_shared<ParallelPort>();
		auto serialPort = std::make_shared<SerialPort>();

		std::shared_ptr<IUSBPort> adapter1 = 
			std::make_shared<ParallelToUSBAdapter>(parallelPort);
		std::shared_ptr<IUSBPort> adapter2 = 
			std::make_shared<SerialToUSBAdapter>(serialPort);

		adapter1->TransferData("Data from ParallelPort");
		adapter2->TransferData("Data from SerialPort");
	}

	/*
	Test4：适配器的透明性。
	知识点：适配器对客户端透明，客户端只看到目标接口。
	问题：如何在客户端代码中完全隐藏适配细节？
	思路：客户端始终通过目标接口指针操作，不知道适配器存在。
	注意：这是适配器模式的核心价值：改变接口但保持客户端代码不变。
	*/
	static void Test4_AdapterTransparency() {
		std::cout << "----Test4_AdapterTransparency----" << std::endl;

		// 客户端代码
		auto UseUSBPort = [](std::shared_ptr<IUSBPort> port) {
			std::cout << "Port Type: " << port->GetType() << std::endl;
			port->Charge();
			port->TransferData("Generic USB Data");
		};

		// 即使内部用的是旧接口，客户端代码完全一致
		auto parallelPort = std::make_shared<ParallelPort>();
		auto serialPort = std::make_shared<SerialPort>();

		UseUSBPort(std::make_shared<ParallelToUSBAdapter>(parallelPort));
		UseUSBPort(std::make_shared<SerialToUSBAdapter>(serialPort));
	}

	/*
	Test5：双向适配与接口映射。
	知识点：适配器可以是单向也可以双向，取决于需求。
	问题：如何处理不完全匹配的接口？有些方法没有对应的旧方法怎么办？
	思路：根据业务需求选择：
		 - 单向适配：新接口中的某些方法无对应实现，留空或默认处理。
		 - 双向适配：旧接口的功能也能通过新接口调用。
	注意：接口映射要清晰，不要隐藏错误或提供虚假的功能。
	*/
	static void Test5_PartialInterfaceMapping() {
		std::cout << "----Test5_PartialInterfaceMapping----" << std::endl;
		auto parallelPort = std::make_shared<ParallelPort>();
		std::shared_ptr<IUSBPort> adapter = 
			std::make_shared<ParallelToUSBAdapter>(parallelPort);

		// 新接口的 Charge() 在旧接口中没有直接实现，适配器可选择：
		// 1. 留空（无操作）
		// 2. 记录日志
		// 3. 进行必要的初始化
		adapter->Charge();  // 适配器的一个虚拟实现

		adapter->TransferData("data");  // 有真实对应
	}

	/*
	Test6：避免过度适配。
	知识点：不是所有接口不匹配都需要适配器，有时修改客户端代码更合理。
	问题：什么时候不应该用适配器？
	思路：
	  - 如果旧接口是你能控制的，直接改旧接口而不是用适配器。
	  - 如果修改旧代码成本低，重构比适配更好。
	  - 只在无法改变旧接口（第三方库、遗留系统）时才用适配器。
	注意：适配器增加了代码复杂度，过度使用会让系统难以维护。
	*/
	static void Test6_WhenNotToUseAdapter() {
		std::cout << "----Test6_WhenNotToUseAdapter----" << std::endl;
		// 假设这是第三方库提供的旧接口，我们无法改变
		// 这时适配器就很有价值
		auto thirdPartyPort = std::make_shared<ParallelPort>();
		std::shared_ptr<IUSBPort> adapter = 
			std::make_shared<ParallelToUSBAdapter>(thirdPartyPort);

		std::cout << "Using third-party interface through adapter" << std::endl;
		adapter->Charge();
		adapter->TransferData("Wrapped third-party call");
	}
};

int main() {
	AdapterTests::Test1_BasicIncompatibility();
	std::cout << std::endl;

	AdapterTests::Test2_ObjectVsClassAdapter();
	std::cout << std::endl;

	AdapterTests::Test3_AdaptMultipleInterfaces();
	std::cout << std::endl;

	AdapterTests::Test4_AdapterTransparency();
	std::cout << std::endl;

	AdapterTests::Test5_PartialInterfaceMapping();
	std::cout << std::endl;

	AdapterTests::Test6_WhenNotToUseAdapter();
	std::cout << std::endl;

	// ========== 总结 ==========
	// 1) 适配器模式的核心目的是将一个接口转换为客户端期望的另一个接口，
	//    让原本不兼容的对象能够协作。
	//
	// 2) 两种实现方式：
	//    - 对象适配器（推荐）：通过组合持有旧对象，实现新接口，转发调用。
	//    - 类适配器：通过多继承同时继承旧类和新接口，侵入性强。
	//
	// 3) 适配器与装饰器的区别：
	//    - 适配器改变接口以实现兼容，装饰器增强功能但保持接口。
	//    - 适配器关注"接口"，装饰器关注"行为"。
	//
	// 4) 设计原则：
	//    - 客户端通过目标接口使用适配器，对适配细节透明。
	//    - 适配器自身不改变旧对象，只是提供一个"翻译层"。
	//    - 优先用对象适配器（组合），避免多继承的复杂性。
	//
	// 5) 何时使用：
	//    - 与第三方库或遗留系统集成。
	//    - 新旧接口需要共存，迁移成本高。
	//    - 无法直接修改旧接口源代码。
	//
	// 6) 常见场景：
	//    - 接口标准升级（USB2.0 -> USB3.0）。
	//    - 系统迁移（Windows API -> 跨平台 API）。
	//    - 第三方库集成（接收第三方对象但需要统一接口）。

	return 0;
}