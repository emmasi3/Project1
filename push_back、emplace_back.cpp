#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

// 去看哔站 收藏夹 C++，push_back和emplace_back区别

class Person
{
public:
	Person(int age, const std::string& name)
		:m_age(age),
		m_name(name)
	{

	}

private:
	int m_age;
	std::string m_name;
};

int main()
{
	/*
	* 1、这里总结一下（因为我刚看完，现在还有点印象）
	*	push_back() 和 emplace_back() 在处理基础类型时，也就是 int、double、char···
	*	效果是一样的，放心用
	* 2、对于 object 一些复杂的自定义类型，就体现出差距了
	*	Person p1(11, "张三");
	*	push_back(p1);
	*	这里会发生 3件事：
	*	（1）在栈区创建 p1（调用构造函数）
	*	（2）将 p1 拷贝构造到 容器中
	*	（3）调用 Person 的析构函数
	*	可以发现，对于复杂类型，这样的方式是很耗费资源的
	* 3、emplace_back()
	*	emplace_back(11, "张三");
	*	这里该方法会直接在容器元素末尾调用 Person 的构造函数，用户给到方法的参数被用作构造函数
	*	所以只会发生 1次 有参构造
	*	就完事了，损耗大幅度降低
	*	
	* 4、再额外补充一点：
	*	2中的使用 push_back() 传给的是一个左值，那如果是右值呢？
	*	push_back(Person(11, "张三")); 
	*	那么现代编译器在放入容器时，就会调用 move() 进行移动操作（替换原来的拷贝构造）
	* 
	*/


	return 0;
}