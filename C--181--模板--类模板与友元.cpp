#include <iostream>
using namespace std;

template<class T1,class T2>//2.当然，在最上面写了show2()时，里面用到了 Person ，所以要提前“声明”这个东西--Person
class Person;

template<class T1,class T2>
void show2(Person<T1, T2>p)         //2.那么既然编译器认为 这俩不是一个东西，那我就告诉它这是一个东西，直接在上面写
{                                   //函数 show2(),这样先被编译器“看见”，并且，在类内声明友元时，加上类参数列表<>
	cout << p.name << "\t" << p.age << endl;//就能告诉编译器，这俩是同一个东西了
}

template<class T1,class T2>
class Person
{
	friend void show(Person<T1, T2>p)
	{
		cout << p.name << "\t" << p.age << endl;
	}

	/*friend void show2(Person<T1, T2>p);*/
	friend void show2<>(Person<T1, T2>p);

public:
	Person(T1 name,T2 age)
	{
		this->name = name;
		this->age = age;
	}

public:
	T1 name;
	T2 age;
};

//template<class T1,class T2>
//void show2(Person<T1, T2>p) //2.如果你直接这样在类外定义函数，那绝对会报错，因为：类内的show2() 是一个“全局函数”原因：
//{                                          //参照 1.里面的
//	cout << p.name << "\t" << p.age << endl; //但是此时的 类外实现的函数 show2() 是什么？很显然是“函数模板”
//	                                         //这俩不是一个东西啊！！！怎么能够执行正确呢？
//}

void test01()
{
	//1.全局函数--友元--类模板“内”实现
	Person<string, int>p("张三", 18);
	show(p);
	//直接在类内写，类外都不用声明的！，但是，但是，如果 show();这样一般会报错吧。但是都是没传入“参数”的错，但是
	//这里的错--- show 未定义标识符 --由此可见，这不是普通的全局函数，而是“全局函数模板”如果不是"friend"关键字
	//（可能告诉编译器： show 函数是类外的） ，它很有可能会认为这是“成员模板函数”而不是“全局函数”

	//以上对于“全局函数”的解释，他就是“普通的全局函数”上面是我的理解有误！
	//有什么“证据”呢？ 
	//”分辨函数模板和普通函数“的最大区别-- show() 有没有专属的“template<>”有没有？显然没有的嘛！
	//所以，它必然是全局函数
}

void test02()
{
	Person<string, int>p("张三", 18);
	show2(p);
}

int main()
{
	test01();
	cout << endl;
	test02();

	system("pause");
	return 0;
}