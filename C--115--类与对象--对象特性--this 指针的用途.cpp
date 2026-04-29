#include <iostream>
using namespace std;

//1. this 指针指向--- “被调用 的 成员函数 所属的 对象 ”
class Person
{
public:
	Person(int age)
	{
		//1.1 解决同名问题
	  //age = age; 如果这样写，那么会打印错误，因为，形参 age 与 属性 age 同名，编译器，无法区分，所以不行
		this->age = age; //但是如果这样写，就不会发生歧义，this == &p 这是本质
	}

	int age;

	Person& addage(const Person& p)
	{
		this->age += p.age;
		return *this; 
		// 2. 此时，this 的第二个作用，显然，作函数的返回值
	}

};

void test01()
{
	Person p(10);
	cout << p.age << endl << endl;
}

void test02()
{
	Person p1(10);
	Person p2(10);
	p2.addage(p1).addage(p1).addage(p1);
	// 2. 这样可以让年龄相加 p1+p2 ,但是，我想要再加一次，而且是在一句代码中，咋办？
	// p2.addage(p1).addage(p1); 这样行不行？不行，因为，函数的返回值，不是 p2 本身，所以要返回对象本身，而且不能
	//        是“值传递”因为这样操纵的是，副本
	cout << p2.age << endl;
}  // . 好了，这样就完美了

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}