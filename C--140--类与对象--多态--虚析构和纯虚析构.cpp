#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() = 0;
	virtual ~Animal() = 0;//2. 纯虚析构和纯虚函数不一样，基本语法一致，但是，纯虚函数只需要有声明即可，不用写，实体
	                      // . 但是，纯虚析构---“声明，定义”，一样都不能少，原因：
	                      // . 如果没有主体，那么将来，如果父类也在堆区有申请的空间，那么析构函数将无法释放，所以
	                     //  . 必须要有，主体
}; 
Animal::~Animal()
{
	cout << "父类析构函数" << endl;
}


class Cat :public Animal
{
public:
	Cat(string name)
	{
		this->name = new string(name);
	}

	void speak()
	{
		cout << *this->name << "在说话" << endl;
	}

	~Cat()
	{
		cout << "Cat析构函数" << endl;
		delete name;
		name = NULL;
	}

	string* name;
};

void test01()
{
	Animal* mao = new Cat("小猫");
	mao->speak();

	delete mao;  //1. 执行这一行代码时，因为 mao 是Aniaml类型 的一个指针---可能类似于一个对象吧，就相当于在释放它的对象
	mao = NULL;  // . 所以释放它时会调用，Animal 的析构函数，但是
}                // . 并不会调用 Cat 的析构函数，这就导致，如果Cat 的实例化对象有 new申请的空间，就不会被释放，内存泄漏

//2. 而“纯虚析构”可以解决这个问题
int main()
{
	test01();

	system("pause");
	return 0;
}//3. 除了“菱形继承”外，基本上跟“虚”沾边的东西，都是因为：子类中的某些函数或者成员无法调用（用作用域直接出错）
 // . 时，采用“虚”的技术！！！！

//4. 当然，“虚析构”也可以解决这个问题

//5.“纯虚析构”--- 会导致变为 ；；； 抽象类，无法实例化对象
// .“虚析构”  --- 没有这些问题