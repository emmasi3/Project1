#include <iostream>
using namespace std;

class Person
{
public:
	//1. 浅拷贝

	Person(int age0, int height0) 
	{
		age = age0;
		cout << &height0 << endl;

		height= new int(height0);// . 传进来的 height0 与 new int(height0) ，不是同一个东西，而是拷贝后的，地址不同
		                         // . 但是，在“堆区”用 new 申请了一块内存后，必须由我们自己释放，编译器，不会自动释放
		cout << height << endl;
	}

	~Person() //2. 一般释放工作，由析构函数执行
	{
		delete height;
		height = NULL;
		// . 这两行是一个标准的，释放代码
		// . 但是，你会发现，报错了，这是因为：
		// . 在 tset01() 执行完毕时，先执行 p2 的析构函数，也就是 p2.height 指向的内存空间被释放了，
		// . 但是，还会继续 执行 p1 的析构函数，但此时，那块空间已经被释放了，再次释放，显然不合法，所以会报错
		//
		// . 为了解决这个 “浅拷贝” 带来的问题，就有了“深拷贝”
		cout << "析构函数的调用" << endl;
	}


	//3. 深拷贝 --用来解决“浅拷贝”释放内存问题--根本原因是--要清理的东西是同一个，指针的指向一致
	// . 那么，让它俩指向不同的空间--并且，拷贝相同的东西，就可以完美解决了
	Person(const Person& p)
	{
		age = p.age;
		height = new int(*p.height);
		// 所谓，深 拷贝，其实就是一种实际工作情况中遇到的问题，并由此提出的解决方法
		// 重在理解，在这个原理下，当然还有很多版本的“深”拷贝 代码，句句不同，但都是为了解决 浅拷贝 的（释放）问题
	}

	int age;
	int* height;
};

void test01()
{
	Person p1(18, 160);
	Person p2(p1);// 如果就这样传进去了，就是一个浅拷贝，因为-- 系统默认执行 拷贝构造函数--仅有 全部 拷贝属性赋值操作
	              // .这就是--- 浅拷贝，
	              

	cout << "p1年龄：" << p1.age << "  身高：" << *p1.height << endl;
	cout << "p2年龄：" << p2.age << "  身高：" << *p2.height << endl;

}




int main()
{
	test01();

	system("pause");
	return 0;
}//4. 一个非常重要的点---- ~Person();析构函数的执行时机是在什么时候？
 // . p1 被创建在 test01() 函数内，也就是 “块”内，在test() 被在 main() 中执行完毕后， p1 才执行析构函数，
 // . 并且，test01() 中有两个对象 p1,p2,先执行哪个的析构呢？--- 先执行后面的 p2 的析构，然后再执行p1 的析构
 // . 
 // . 而 隐匿对象 Person(10); 这句代码，刚执行完，就被释放，有个对照，好记忆