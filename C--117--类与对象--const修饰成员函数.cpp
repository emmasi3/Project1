#include <iostream>
using namespace std;

class Person
{
public:
	void f() const
	{
		// a = 1000; 这句代码是报错的，因为：const 修饰函数为“常函数”，里面不可以修改属性，本质：：
		// this->a = 1000; 上一句代码 ，本质是这样的，const Person const * this,
		// 1. this 本质为：指针常量，和“引用”一样，指针指向不可以修改，而常函数--实质上是对 this 修改，使得
		//  . this 指向的值都不可以改变，所以里面的“普通成员变量”都不可以改变

		this->b = 100;
		cout << b << endl;
	}

	void f2()
	{
		cout << "普通函数f2()" << endl;
	}

	int a = 10;
	mutable int b = 20;
	// 3. 虽然在 f() 常函数中无法直接修改 属性值，但是一旦属性用 mutable 修饰，便可以进行修改，即使在 f() 常函数中
};

void test01()
{
	Person p1;
	p1.a = 100;
	p1.f();
	//2. 创建一个普通“对象”，可以访问“常函数” ！！！！  常函数，也可以访问“普通成员  变量 ”，但不能修改
	const Person p2;
 // p2.f2();
	// . 但是“常对象”，不可以访问“普通函数”,因为：
	// . 常对象 p2 的属性以及其他东西，本身是不允许修改的，但是，普通函数，可以间接的修改  本不允许修改的 属性值
	// . 所以，常对象不被允许调用普通函数，只能调用常函数
	p2.f();

	//3. b 是用 mutable 修饰的，属于“常对象 p2” 中可以修改的特殊的“属性值”
	p2.b = 1000;
	cout << p2.b << endl;

}

/*
* 4、做服务器项目时，遇到了一些问题，补充一下，函数 () 后面用 const 修饰：
* std::string LoggerManager::toYamlString() const 
* std::string LoggerManager::toYamlString(LoggerManager* const this)
* 
* 仅仅是对于 this 指针做了一些限制而已，没有用 mutable 修饰的成语变量，统统都不能修改，
* 但是对于函数内的其他东西，例如：局部变量 std::stringstream ss，改变无所谓，没有 const 修饰
* 当时有点疑惑，有点忘记了，记住就好
*/

int main()
{
	test01();

	system("pause");
	return 0;
}