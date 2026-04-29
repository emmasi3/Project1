#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()                
	{
		cout << "动物在说话" << endl;
	}
};

class Cat:public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//                            void test01(Cat& animal)-- 正常
void test01(Animal &animal) // 1. 正常来说，我们传入一个对象，肯定将传入类型写为 Cat,这时候 animal.speak()就是Cat 类中的
{                           //  . “小猫在说话”，但是如果传入类型写为 Animal 这是 Cat 的父类，然后实际传入的是 Cat 对象
	animal.speak();		    //  . 当然，这不会报错， animal.speak()依旧会执行，实质：“Animal &animal=mao;”    ，
	                        //  .这个意思是“用父类的指针或引用指向子类的对象”
							// 但是

}                           //  . 这时候结果为“动物在说话”，也就是，它实际调用的是父类 Animal 中的 speak()函数，而我们想要
							//  . 调用的是-- Cat 里面的同名函数，。。。 原因：Animal 中的函数的地址，是在“编译”阶段就
							//  . 依旧确定下来的,animal.Cat::speak(); 即使你这样通过作用域调用Cat中的 speak(),会直接报错，
                            //  . 原因不明？
void test02(Animal &animal)
{
	animal.speak();
}

// 1. 解决的方法：用 virtual 修饰函数Animal 中的函数 speak() ，---> 虚函数！！！，下节课再谈原因！！！
// 
// 2. 这种方法实际上是-- 动态多态，多态-----指的是一个“父类成员函数”speak()在 被不同的“子类对象”调用时，能够瞬间变为
//  . 调用“该子类对象”中的同名函数 speak()。。 一个函数，多种调用状态

// 3.  “动态多态”的满足条件 --- 
// 有继承关系。。
// 父类中有虚继承函数，子类中有与父类一摸一样的成员函数。。
// 在调用虚继承函数时，参数为：“Animal &animal=mao;” “用父类的指针或引用指向子类的对象”。。

//  . 满足以上三点，就可以说 创造了一个“动态多态”--   virtual void speak();

// 4. 动态多态的作用--让父类中的函数的地址，晚绑定 -- 使得 在 test01()中 animal.speak() 调用 函数 speak() 时他的地址没有
//  . 被确定，也就是现在 计算机并不知道 应该调用哪个 speak() ，父类还是子类？
//  . 这时编译器会自动查看 你调用函数时用的哪个对象
//  . 如果是 mao ，就会调用 mao::speak() ，狗也一样，当然你也可以写 animal.Animal::speak(); 直接调用 父类中的speak()
//  . 灵活多变，即为“动态多态”

// 5. “重写” -- 定义 -- 子类中“写”有与父类一摸一样的成员函数。。

int main()
{
	Cat mao;
	test01(mao);

	Dog dog;
	test02(dog);

	system("pause");
	return 0;
}