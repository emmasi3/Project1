#include <iostream>
using namespace std;

class f
{
public:
	f()
	{
		this->num = 0;
	}

	int operator()(int a,int b)
	{
		num++;
		return a + b;
	}

	int num;
};

void myprintf(f& f)
{
	cout << "f仿函数被调用" << endl;
}

void test01()
{
	f f;
	cout << f(10, 20) << endl;// . 所谓函数对象 -- 并不是函数，而是重载 () 运算符的一个类，创建了 f的实例化对象后
	                          //  . 利用() 重载运算符 调用成员函数的结果 -- 俗称：“仿函数”，
                              //上述所见，f(10,20) 的调用方式和函数一模一样，所以叫仿函数
	f(10, 20);
	f(10, 20);
	f(10, 20);
	f(10, 20);
	cout << f.num << endl;//可以看见现在的仿函数 f() 的状态 -- 被调用了多少次？--- 2点

	myprintf(f);
	
}
//1.仿函数可以以有参数，可以有返回值
//2.函数对象可以拥有自己的状态
//3.函数对象可以作为参数 （因为他的本质是一个类对象）

int main()
{
	test01();

	system("pause");
	return 0;
}
/*
* 1、在我学习 -- 服务器学习 -- 项目时，遇到的问题，
* 类模板默认参数  FromStr = LexicalCast<T, std::string>
* 
* 这个LexicalCast是一个重载了 () 的类，俗称 -- 仿函数
* 但是在调用的时候，setValue(FromStr()(val))，
* 可是上面的例子，不是说 f(10, 20)就可以了吗？
* 你看清楚，f f; 这个f是一个已经实例化的对象了，再次调用 () 就会调用相应的重载函数，
* 
* 但是项目中的情况却不是这样的，FromStr = ···这仅仅是一个类模板的默认参数，没有涉及到实例化对象，说白了就是一个类型的说明
* FromStr()(val) 是创建一个“临时对象”然后临时对象再去调用重载函数，嗯嗯，明白了吧
* 
*/