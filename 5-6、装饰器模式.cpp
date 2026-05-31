#include <iostream>
#include <memory>
#include <string>
#include <utility>

// 装饰器模式示例集合：每个静态方法都是一个小测试，分别体现一个知识点、
// 一个常见问题、对应解决思路和注意事项。

// 统一抽象：组件接口
struct IDrink {
	virtual ~IDrink() = default;
	virtual std::string Name() const = 0;
	virtual double Price() const = 0;
};

// 具体组件：基础咖啡
struct BlackCoffee : IDrink {
	std::string Name() const override {
		return "BlackCoffee";
	}

	double Price() const override {
		return 10.0;
	}
};

// 装饰器基类：保存被装饰对象，自己也实现同一接口
struct DrinkDecorator : IDrink {
	explicit DrinkDecorator(std::shared_ptr<IDrink> drink)
		: drink_(std::move(drink)) {}

protected:
	// 被修饰对象
	std::shared_ptr<IDrink> drink_;
};

// 具体装饰器：加牛奶
struct MilkDecorator : DrinkDecorator {
	using DrinkDecorator::DrinkDecorator;

	std::string Name() const override {
		return drink_->Name() + " + Milk";
	}

	double Price() const override {
		return drink_->Price() + 2.0;
	}
};

// 具体装饰器：加糖
struct SugarDecorator : DrinkDecorator {
	using DrinkDecorator::DrinkDecorator;

	std::string Name() const override {
		return drink_->Name() + " + Sugar";
	}

	double Price() const override {
		return drink_->Price() + 1.0;
	}
};

// 具体装饰器：加奶油
struct CreamDecorator : DrinkDecorator {
	using DrinkDecorator::DrinkDecorator;

	std::string Name() const override {
		return drink_->Name() + " + Cream";
	}

	double Price() const override {
		return drink_->Price() + 3.0;
	}
};


/*
* @brief 测试模块的统一类
*/
struct DecoratorTests {
	static void Print(const IDrink& drink) {
		std::cout << drink.Name() << " , Price=" << drink.Price() << std::endl;
	}

	/*
	Test1：基础组件。
	知识点：装饰器模式一定先有统一抽象，客户端先能单独使用基础对象。
	问题：如果一开始就依赖具体类，后续扩展会把业务写死。
	思路：先让基础组件独立工作，再在外层叠加装饰。
	注意：组件接口要稳定，且析构函数必须是虚函数。
	*/
	static void Test1_BasicComponent() {
		std::cout << "----Test1_BasicComponent----" << std::endl;
		auto drink = std::make_shared<BlackCoffee>();
		Print(*drink);
	}

	/*
	Test2：单个装饰器。
	知识点：装饰器通过组合对象来增加新职责，而不是修改原类。
	问题：如果为了加牛奶去继承出一个新咖啡类，会快速产生类爆炸。
	思路：把基础对象交给装饰器，由装饰器负责追加名称和价格。
	注意：装饰器和组件要实现同一接口，客户端才能透明使用。
	*/
	static void Test2_SingleDecorator() {
		std::cout << "----Test2_SingleDecorator----" << std::endl;
		auto drink = std::make_shared<MilkDecorator>(
			std::make_shared<BlackCoffee>());
		Print(*drink);
	}

	/*
	Test3：多个装饰器叠加。
	知识点：装饰器可以一层套一层，形成链式增强。
	问题：功能组合一多，如果靠继承实现，每一种组合都要单独写类。
	思路：每个装饰器只做一件事，然后按需组合。
	注意：每一层都应该只关心自己的扩展逻辑，别把别人的职责也塞进来。
	*/
	static void Test3_MultiDecoratorStack() {
		std::cout << "----Test3_MultiDecoratorStack----" << std::endl;
		auto drink = std::make_shared<SugarDecorator>(
			std::make_shared<MilkDecorator>(
				std::make_shared<BlackCoffee>()));
		Print(*drink);
	}

	/*
	Test4：装饰顺序。
	知识点：装饰器是有顺序的，不同顺序可能得到不同结果。
	问题：同样是牛奶和糖，先后不同，最终描述字符串的顺序就不同。
	思路：把“层级顺序”当作业务规则的一部分来设计。
	注意：如果业务要求顺序固定，就不要随意在外层乱套。
	*/
	static void Test4_OrderMatters() {
		std::cout << "----Test4_OrderMatters----" << std::endl;
		auto first = std::make_shared<MilkDecorator>(
			std::make_shared<SugarDecorator>(
				std::make_shared<BlackCoffee>()));
		auto second = std::make_shared<SugarDecorator>(
			std::make_shared<MilkDecorator>(
				std::make_shared<BlackCoffee>()));
		Print(*first);
		Print(*second);
	}

	/*
	Test5：运行期动态装配。
	知识点：装饰器最适合在运行时按条件组合功能。
	问题：如果把各种组合都提前写死，扩展和维护都会很麻烦。
	思路：根据开关逐层包装对象，形成灵活的构建过程。
	注意：客户端只关心最终抽象，不要让它知道太多具体装饰器细节。
	*/
	static std::shared_ptr<IDrink> BuildDrink(bool addMilk, bool addSugar, bool addCream) {
		std::shared_ptr<IDrink> drink = std::make_shared<BlackCoffee>();

		if (addMilk) {
			drink = std::make_shared<MilkDecorator>(drink);
		}

		if (addSugar) {
			drink = std::make_shared<SugarDecorator>(drink);
		}

		if (addCream) {
			drink = std::make_shared<CreamDecorator>(drink);
		}

		return drink;
	}

	static void Test5_RuntimeComposition() {
		std::cout << "----Test5_RuntimeComposition----" << std::endl;
		auto drink = BuildDrink(true, true, false);
		Print(*drink);
	}

	/*
	Test6：透明使用和生命周期管理。
	知识点：装饰器和组件都要通过同一抽象引用来使用，所有权最好交给智能指针。
	问题：如果用裸指针手动管理，层层包装后很容易出现泄漏或悬空指针。
	思路：用 shared_ptr 保存被装饰对象，让外层对象自动持有内层对象。
	注意：shared_ptr 适合简单示例，真实项目里还要警惕循环引用。
	*/
	static void Test6_TransparentUsageAndLifetime() {
		std::cout << "----Test6_TransparentUsageAndLifetime----" << std::endl;
		auto drink = std::make_shared<CreamDecorator>(
			std::make_shared<MilkDecorator>(
				std::make_shared<BlackCoffee>()));
		std::shared_ptr<IDrink> baseView = drink;
		Print(*baseView);
	}
};

int main() {
	DecoratorTests::Test1_BasicComponent();
	DecoratorTests::Test2_SingleDecorator();
	DecoratorTests::Test3_MultiDecoratorStack();
	DecoratorTests::Test4_OrderMatters();
	DecoratorTests::Test5_RuntimeComposition();
	DecoratorTests::Test6_TransparentUsageAndLifetime();

	// 总结：
	// 1) 装饰器模式的核心是“组合优先于继承”，通过包装对象来增加 “功能”。
	// 2) 组件和装饰器必须实现同一抽象接口，客户端才能透明地使用它们。
	// 3) 装饰器可以层层叠加，适合做运行期的功能组合。
	// 4) 装饰顺序会影响最终结果，顺序本身就是业务的一部分。
	// 5) 实际开发中要注意生命周期管理、空指针保护和循环引用问题。
	// 6) 适合的场景：权限、日志、缓存、压缩、加密、UI增强、文本处理等。

	// 1、如果 1）中通过继承子类来增加功能，那么工作量将会很大，不划算，通过交给具体的
	//		装饰器，来处理需要装饰的对象(增加对应的功能)，这样就很好了，如果后续不需要
	//		某些功能，只需要取消对应的 “装饰” 即可
	//		对象只需要保留最基础、最通用、稳定的功能即可

	return 0;
}
