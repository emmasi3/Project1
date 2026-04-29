#include <iostream>
using namespace std;

class Person
{
public:
	void steage()
	{
		cout << *this->age << endl;
	}
public:
	Person& operator=(const Person &p2)// . = 号的重载，负责简化深拷贝的工作量-具有深拷贝的功能，
	{
		int* AGE = new int(*p2.age);
		this->age = AGE;
		return *this;
	}
public:
	Person(int age)
	{
		this->age = new int(age);
	}

	~Person()
	{
		if (age != NULL)// 1.一个浅拷贝处理内存的常见问题，清理两遍同一个-- 采用“深拷贝”但是，要求：给 = 符号重载
			            //  .使它具有“深拷贝”的功能------ 也就是直接 p1 = p2; 之后，清理不报错
		{
			delete age;
			age = NULL;
		}
	}
private:
	int *age;
};

void test01()
{
	Person p1(18);
	Person p2(20);// . 创建两个对象
	Person p3(999);
 // p1 = p2;-> p1=Person(p2)--实质是：浅拷贝，因为会调用“默认拷贝构造函数”，会将 p2 的所有属性值都拷贝给p1
 //                  . 之后同一个类的对象之间才可以这样做！！
	//               . 那么现在是不是要释放 new int(age)，因为这是在“堆区”申请的，所以必须手动释放，释放时机就在~Person()
	//               . 析构函数被调用时 
	p1 = p2;
	p2.steage();
	p1.steage();
	// 2. 链式编程思想   
	// . a=b=c; 这句代码在 c++ 中是允许存在的，从右往左，开始执行，所以，最后的 a,b,c 的值都等于 c 开始的值
	// . 那么 p1=p2=p3; 是否也能如此呢？
	// . 首先看看， p2=p3,实际上是调用了一个成员函数， p2.operator(p3),所以函数整体返回值结果为 void 
	// . 那么 p1=p2 的操作，肯定会报错， 因为： p1=void 这是不合法的
	// . 那么就在“返回值”的身上下手
	cout << endl;
	p1 = p2 = p3; //看，这下就不报错了，
	p3.steage();
	p2.steage();
	p1.steage();

	// 3. “链式编程思想”的实现，主要体现在返回值是否可以被当作下一次程序的开始，也就是返回值本身的问题
}

int main()
{
	test01();

	system("pause");
	return 0;
}