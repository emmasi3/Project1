#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()             //1. 定义虚函数后，Animal 中会有一个 vfptr 指针，sizeof(Animal) 也会从 1 变为4  
	{                                //原因：成员函数speak()没在类Animal 上，所以本身为空实现，自动分配内存1 ，定义虚函数后
		cout << "动物在说话" << endl;//自动生成 vfptr “虚函数指针”，占 4 个字节的空间。。。。
	}                                //vfptr 指向 虚函数表 vftable,这里面储存了一个“实函数”speak()的地址，
};

class Cat :public Animal
{
public:
	void speak()  // 2. 函数的“重写”这是“动态多态”的条件之一，如果没有重写，仅仅只是 class Cat :public Animal{}
	{             //而且内部是空实现的前提下，会继承 Animal 的指针 vfptr 以及 vftable ，这里面储存的是 Animal::speak()函数
		cout << "小猫在说话" << endl;//的“地址”，
	}             //但是，如果你进行了“重写”，也就是让Cat有自己的成员函数（虚函数），在继承前者的 虚函数表时，会用
};                //子类的重写的 Cat::speak()函数的“地址”进行“覆盖”操作，（那里本来储存着父类的speak()地址）
                  //此时“Cat自己的虚函数表”中会有自己的“实函数
                  //的“地址”

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl; //3. 这调用mao.speak()时，会访问mao的vfptr 指针，然后访问储存地址显示的空间，调用
	}                          //mao中的speak()函数
};

                                 // 这就是全部的多态实现的“底层原理及剖析”--- 桌面上有图片，B站上也有，自己看

void test01(Animal &animal) //4. 最后一个问题：为什么 用 “用父类的指针或者引用指向子类的对象”后，用animal.Cat::speak()
{                      //不能够调用想要的speak()？而 直接void test01(Cat &animal);却可以直接 animal.Cat::speak()却可以得到想要的
	                  // 多态就是为了复杂吗？那为啥要用它 ？
	animal.speak();     //这就涉及到了 多态的作用和好处--，这在后面的会讲，
						 //所以，“为了”这个好处，才有了多态，以及如何正确规避一些问题。

	              //5. 当你“用父类的指针或者引用指向子类的对象”后，（Animal &animal），编译器会认为，父类中的“实函数”
}                 //是一个“静态多态”所以在编译阶段就确定了 speak()的地址，这时，子类继承父类时，会将“重写的函数”地址
                  // 进行“覆盖”操作（这个真的是我自己想的，类比真真的多态的实现，很大可能是错误的），导致，子类中的实函数
                  //地址确实存在，但是被覆盖了，所以animal.Cat::speak()，不能调用Cat::作用域下的speak()了，只能是报错

int main()
{
	Cat mao;
	test01(mao);

	Dog dog;
	test01(dog);

	// 5. 当然上面这个说法，我感觉是错的！！！可能是人为规定的，在“用父类的指针或者引用指向子类的对象”后
// 就不能再次在“这个函数”主体内 animal.Cat::speak() 用Cat 的作用域了，这绝对特么是人为规定的！！！
	mao.speak();
	// 上面这个例子，在函数 test01()执行完毕后，再次 mao.speak() 即使在父类中，没有虚函数的存在，也可以调用想要的函数
	// 因为：动态多态的条件之一是：“用父类的指针或者引用指向子类的对象”后，没这样做，virtual 写了和没写一样，屁用没有
	system("pause");
	return 0;
}