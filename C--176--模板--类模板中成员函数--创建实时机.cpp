#include <iostream>
using namespace std;

class Person1
{
public:
	void show1()
	{
		cout << "show1的调用" << endl;
	}
};

class Person2
{
public:
	void show2()
	{
		cout << "show2的调用" << endl;
	}
};

template<class T>
class myclass
{
public:
	T obj;

	void func1()//1.可以看看现在的 obj.show() 这个调用没有报错？可是明明 show()没有在 obj 里面啊。
	{
		obj.show1();  //原因：1. T obj; 这个对象的数据类型并没有确定下来（但仅仅是这样，应该还是会报错啊）
		              //      2. 生成过程中，func() 这俩函数根本没有被“创建”，也就是根本没有编译这一行
	}
	void func2()
	{
		obj.show2();
	}
};

void test01()
{
	myclass<Person1>p1;
	p1.obj.show1();
	p1.func1();
	//上述这三行代码，
	//第一行：指定了 T 的含义"Person1"，所以 T obj == Person1 obj
	//第二行：p1.obj.show1();也就只能调用 Person1 中的函数func1()
	//第三行：p1.func1() == p1.obj.show1() 
	
	//而此时，我们调用函数 func2()----  p1.func2(); 绝对会报错，是因为func2()不是 Person2 的成员函数，obj 是 Person1 的
	//实例化对象，所以报错

	//总结：（1）类模板中，func()成员函数不是一开始就被创建的，而是在调用时才被创建
	//证明（1）中结论，用反证法
	// 
	//假设，func()成员函数一开始就被创建，那么就会报错（obj 的数据类型没有确定，也就是其中还没func()这个函数存在）
	//而这与实际（没有报错）不相符
	//所以：“类模板”中func()成员函数一开始没有被创建
}

int main()
{
	test01();

	system("pause");
	return 0;
}