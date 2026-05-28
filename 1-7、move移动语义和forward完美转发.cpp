#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

using namespace std;

// 知识点1：引用折叠 + 万能引用（转发引用）
static void test1()
{
    cout << "========== test1：引用折叠 + 万能引用 ==========" << endl;

    // 用法总结：
    // 1) 引用折叠规则（核心记忆：有左值引用就折叠成左值引用）
    //    T&  &  -> T&
    //    T&  && -> T&
    //    T&& &  -> T&
    //    T&& && -> T&&
    // 2) 模板中形如 T&& 且 T 需要推导时，T&& 是万能引用（转发引用）。
    //    - 传左值：T 推导为 U&，参数类型折叠后为 U&
    //    - 传右值：T 推导为 U， 参数类型为 U&&

    auto printCategory = [](auto&& x)
    {
        using T = decltype(x);
        if constexpr (is_lvalue_reference_v<T>)
        {
            cout << "当前参数是左值" << endl;
        }
        else
        {
            cout << "当前参数是右值" << endl;
        }
    };

    int a = 10;
    printCategory(a);   // 左值
    printCategory(20);  // 右值

    // 注意事项：
    // 1) “万能引用”只在“类型推导场景”成立；若类型已确定，T&& 就是纯右值引用。
    // 2) 形参名本身在函数体内永远是左值（即使它的类型是 T&&）。
    // 3) 若要继续保持实参值类别，必须配合 std::forward<T>(param)。
}

// 知识点2：std::move
static void test2()
{
    cout << "========== test2：std::move ==========" << endl;

    // 用法总结：
    // std::move 本质是一个类型转换（static_cast<T&&>），
    // 用于把表达式“显式地”转换为右值，从而触发移动构造/移动赋值。
    string s1 = "hello move";
    string s2 = std::move(s1);

    cout << "s2 = " << s2 << endl;
    cout << "s1(被移动后) = " << s1 << endl;

    // 注意事项：
    // 1) std::move 不会真的移动资源，真正移动发生在后续对象支持移动语义时。
    // 2) 被 move 后的对象处于“有效但未指定状态”，可析构、可重新赋值，
    //    但不应依赖其原值。
    // 3) 不要对还要继续稳定使用的对象随意 move，避免逻辑错误。

}

// 知识点3：std::forward（完美转发）
template <typename T>
void sink(T&& x)
{
    if constexpr (is_lvalue_reference_v<T>)
    {
        cout << "sink收到：左值" << endl;
    }
    else
    {
        cout << "sink收到：右值" << endl;
    }
}

template <typename T>
void wrapper(T&& x)
{
    // 用法总结：
    // std::forward<T>(x) 会按 T 的推导结果“有条件”转发：
    // - 若实参原本是左值，则转发成左值
    // - 若实参原本是右值，则转发成右值
    sink(std::forward<T>(x));
}

static void test3()
{
    cout << "========== test3：std::forward（完美转发） ==========" << endl;

    int a = 100;
    wrapper(a);    // 保持为左值
    wrapper(200);  // 保持为右值

    // 注意事项：
    // 1) std::forward 通常只用于“转发引用（T&&）”参数。
    // 2) forward 需要写成 std::forward<T>(param)，模板实参 T 必须对应原始推导类型。
    // 3) 若这里只用 std::move，会把左值也强行转成右值，破坏语义。
}

int main()
{
    // 知识点总览：
    // 1) 引用折叠 + 万能引用：理解模板推导后参数最终是左值引用还是右值引用。
    // 2) std::move：把表达式转成右值，尝试触发移动语义。
    // 3) std::forward：在转发场景下保留实参原始值类别，实现完美转发。

    // test1：演示引用折叠规则、万能引用判定，以及“形参名永远是左值”的注意事项。
    test1();

    // test2：演示 std::move 的本质、移动后对象状态，以及避免误用 move 的注意事项。
    test2();

    // test3：演示 std::forward 在包装函数中保持值类别，实现完美转发及其使用前提。
    test3();

    /*
    * std::forward<T>()
    * 这个完美转发的使用场景，或者说什么问题的背景下，需要这个功能？
    * 问题：test3() --> wrapper(200)，通过引用折叠 + 万能引用后，wrapper() 中的
    *       形参x，它的类型被推导为 T : int&&，右值引用，但同时 x 也是一个 “左值”，
    *       好！我们现在需要 sink(x); 让他走 其中的 else 分支，或者说，
    *       在对应的 b站视频课中，我们传递 x，想要让他走 (const std::string&& str)
    *       这个右值引用版本的重载函数！
    *       好，现在调用 sink(x); 那么他只会走 if 分支，永远不会走 else 分支
    *       实际场景中：wrapper(200) 是对外开放的接口，内部的 sink 不对外开放
    *       你作为一个使用者，总不会去修改库中的逻辑吧？那太多了，不现实！
    *       那要如何才能够做到，开发者只用调用 wrapper(200)，便能够使得最终调用的方法
    *       和 200 这个 “右值引用” 挂钩呢？也就是和我们想要他走的分支 or 重载函数版本一致呢？
    *       
    * 解决思路：引用折叠 + 万能引用 --> 推导出 T 正确类型，这是一个推导出来的类型
    *       ok，现在只需要让 sink() 直到他接收的是一个 T 类型的参数即可锁定到正确的分支
    *       or 重载版本
    *       那么 std::forwrad<T>(x) 返回的就是这么一个 T 类型的东西，解决了吧？
    * 
    * 调用链路：test3() --> wrapper(200) --> sink(std::forward<T>(x)) --> else 分支
    * 
    * 好，类比推理，从 move 到 forward，它的实现中：static_cast<_Ty&&>(_Arg)
    * 使用的就是一个静态强转
    * 
    * 总结：1、这些知识点，都是围绕着 “左值引用、右值引用、左值、右值” 来进行展开的，这四个东西
    *       就像在现代的 C++ 标准库中无处不在，共同构建了整个标准库的实现，包括但不限于
    *       STL 库中的很多东西
    *       2、例如：std::move() 之前我一直理解的是，他叫 “移动语义”
    *       那么也就是他将一个对象中的很多资源都给到了 另一边？
    *       那么对于很多的自定义类型，他也会自动这样子做？很明显不现实
    *       std::move() 仅仅会返回该对象的 “右值引用”，
    *       （1）
    *           {std::string src = "hello";
    *           std::string dst = std::move(src);}
    *           上述代码中，强制返回 src 的右值引用，
    *           给到标准库中 std::string 的移动构造实现
    *           std::string(std::string&& src) noexcept
    *           {this->_Px = src._Px;
    *           src._Px = nullptr;
    *           ···}
    *        这下你看清了吧？std::move() 仅仅是标准库中的一个强转函数而已
    *       关键是：标准库中的很多东西，C++标准的各种容器和对象，凡是支持
    *       拷贝、移动、构造的对象，都会重载 “移动构造” -- 也就是接收 “右值引用”
    *       的构造函数、赋值函数 -- operator=(std::string&& src) ···
    *       这才是 std::move() 能够被称为 “移动语义” 的原因
    *       因为只要开发者 给自定义类型重载了移动构造、··· 方法，并且使用合适的
    *       语法调用 std::move()，那么就会触发这些 “写好的” 移动方法，达到移动的目的
    *       懂了吧？
    *       3、std::move() 之后，调用的类的 移动构造、移动赋值运算符···，都应该采用 noexpect
    *       防止在进行这些行为时，throw 异常，导致 “移动” 行为执行到一半停下来了，此时
    *       资源已经被移动了一部分，也就是 “移动 && 接受” 双方，现在都是不完整的，至于报错
    *       等到 “移动” 行为完成后，在处理报错，至少保证有 一方 是完整的，
    *       所以为了保证 “移动” 行为的完整性，必须要使用 noexcept 声明方法
    *           
    */

    return 0;
}
