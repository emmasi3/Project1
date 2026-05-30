#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

// ================================
// 1) 产品层：统一抽象 + 具体产品
// ================================
class Product {
public:
    virtual ~Product() = default;
    virtual string Name() const = 0;
    virtual void Use() const = 0;
};

class Phone : public Product {
public:
    string Name() const override { return "Phone"; }
    void Use() const override { cout << "使用手机" << endl; }
};

class Laptop : public Product {
public:
    string Name() const override { return "Laptop"; }
    void Use() const override { cout << "使用笔记本" << endl; }
};

class Tablet : public Product {
public:
    string Name() const override { return "Tablet"; }
    void Use() const override { cout << "使用平板" << endl; }
};

// ================================
// 2) 简单工厂：集中创建
// ================================
class SimpleFactory {
public:
    static unique_ptr<Product> Create(const string& type) {
        if (type == "phone") return make_unique<Phone>();
        if (type == "laptop") return make_unique<Laptop>();
        if (type == "tablet") return make_unique<Tablet>(); // 新增产品需改这里
        throw invalid_argument("不支持的产品类型: " + type);
    }
};

// ================================
// 3) 工厂方法：抽象工厂 + 具体工厂
// ================================
class ProductFactory {
public:
    virtual ~ProductFactory() = default;
    virtual unique_ptr<Product> Create() const = 0;
};

class PhoneFactory : public ProductFactory {
public:
    unique_ptr<Product> Create() const override { return make_unique<Phone>(); }
};

class LaptopFactory : public ProductFactory {
public:
    unique_ptr<Product> Create() const override { return make_unique<Laptop>(); }
};

class TabletFactory : public ProductFactory {
public:
    unique_ptr<Product> Create() const override { return make_unique<Tablet>(); }
};

class Demo {
public:
    /**
     * 知识点：简单工厂的基本用法（一个工厂按参数创建不同产品）
     * 遇到的问题：客户端直接 new 多种对象，创建逻辑分散。
     * 解决思路和方法：把对象创建统一放到 SimpleFactory::Create。
     * 注意事项：type 参数建议统一规范（如常量/枚举），避免字符串拼写错误。
     */
    static void TestSimpleFactoryBasic() {
        auto p1 = SimpleFactory::Create("phone");
        auto p2 = SimpleFactory::Create("laptop");
        cout << "[简单工厂-基本] " << p1->Name() << ", " << p2->Name() << endl;
    }

    /**
     * 知识点：简单工厂的输入校验与异常处理
     * 遇到的问题：传入非法类型时，可能导致逻辑不明确。
     * 解决思路和方法：工厂内部统一抛出 invalid_argument。
     * 注意事项：调用方应捕获异常并做降级或提示，避免程序直接崩溃。
     */
    static void TestSimpleFactoryValidation() {
        try {
            auto p = SimpleFactory::Create("unknown");
            (void)p;
        }
        catch (const exception& ex) {
            cout << "[简单工厂-校验] 捕获异常: " << ex.what() << endl;
        }
    }

    /**
     * 知识点：简单工厂的扩展成本
     * 遇到的问题：新增产品时，需要修改 SimpleFactory 的分支逻辑。
     * 解决思路和方法：本例通过新增 Tablet 展示“新增即修改工厂”。
     * 注意事项：产品类型增多后，简单工厂会变大，维护成本上升。
     */
    static void TestSimpleFactoryExtensionCost() {
        auto p = SimpleFactory::Create("tablet");
        cout << "[简单工厂-扩展成本] " << p->Name() << endl;
    }

    /**
     * 知识点：工厂方法的基本用法（一个具体工厂对应一个产品）
     * 遇到的问题：希望减少通过字符串选择产品的硬编码。
     * 解决思路和方法：定义 ProductFactory 抽象接口，客户端面向工厂接口编程。
     * 注意事项：工厂方法会增加类数量，但职责更清晰。
     */
    static void TestFactoryMethodBasic() {
        unique_ptr<ProductFactory> f1 = make_unique<PhoneFactory>();
        unique_ptr<ProductFactory> f2 = make_unique<LaptopFactory>();
        auto p1 = f1->Create();
        auto p2 = f2->Create();
        cout << "[工厂方法-基本] " << p1->Name() << ", " << p2->Name() << endl;
    }

    /**
     * 知识点：工厂方法对开闭原则更友好
     * 遇到的问题：新增产品时不希望修改已有工厂逻辑。
     * 解决思路和方法：新增 TabletFactory 即可，不改 PhoneFactory/LaptopFactory。
     * 注意事项：类数量上升时，建议按模块组织目录，保持可维护性。
     */
    static void TestFactoryMethodOpenClose() {
        unique_ptr<ProductFactory> factory = make_unique<TabletFactory>();
        auto p = factory->Create();
        cout << "[工厂方法-开闭原则] " << p->Name() << endl;
    }

    /**
     * 知识点：简单工厂 vs 工厂方法 的选型建议
     * 遇到的问题：两者都能解耦创建，实际项目中如何选。
     * 解决思路和方法：按“变化频率 + 复杂度”决策。
     * 注意事项：模式服务于业务，不要为了模式而模式。
     */
    static void TestComparisonConclusion() {
        cout << "[选型结论] 产品少且变化小 -> 简单工厂；产品扩展频繁 -> 工厂方法。" << endl;
    }
};

int main() {
    Demo::TestSimpleFactoryBasic();
    Demo::TestSimpleFactoryValidation();
    Demo::TestSimpleFactoryExtensionCost();

    Demo::TestFactoryMethodBasic();
    Demo::TestFactoryMethodOpenClose();

    Demo::TestComparisonConclusion();

    // ================================
    // main 总结（知识点回顾）
    // 1) 简单工厂：
    //    - 优点：集中创建、实现简单、上手快。
    //    - 缺点：新增产品通常要改工厂分支，扩展性一般。
    // 2) 工厂方法：
    //    - 优点：新增产品通常新增“产品+工厂”即可，对扩展更友好。
    //    - 缺点：类数量增加，结构相对更复杂。
    // 3) 实战建议：
    //    - 小型/稳定场景：优先简单工厂。
    //    - 中大型/持续扩展场景：优先工厂方法。
    // ================================

    return 0;
}
