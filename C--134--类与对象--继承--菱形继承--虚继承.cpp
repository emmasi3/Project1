#include <iostream>
using namespace std;

class animal
{
public:
	int age = 10;
};

class sheep:virtual public animal
{
public:
	int age = 20;
};

class lu:virtual public animal
{
public:
	int age = 30;
};

class sheeptuo:public sheep,public lu
{
public:

};


void test01()
{
	animal A;
	sheep S;
	lu L;
	sheeptuo T;

	// 1. 这就是菱形继承，sheeptuo 同时继承sheep lu 两个父类，并且，这俩父类共同继承 animal 类，那么在
	//  . sheep，lu 里面就共同拥有 age 这个成员，虽然可以在sheeptuo 中通过作用域准确调用，但是，
	//  . 问题：sheeptuo 这个类中直接继承了 两份来自 最上层的 animal 的 age ，需要这么多吗？很显然不需要，资源浪费了
	//  . 所以为了解决这个问题，引入了 --- “虚继承” 的语句

	// 2. 利用 virtual(翻译为：“虚拟”的意思)，底层实现自己查查，反正是有关于“指针”的东西，那个指针，会指向他们各自的
	//  . 的成员，又因为，在菱形继承中，这俩货中的成员继承的都是父类的，所以，这俩指针会指向同一片内存空间，所以此时，只有
    //  . 一个 age 成员---在 T 的对象中

	// 3. 我理解的还是不够底层，所以你要继续看课理解
}

int main()
{


	system("pause");
	return 0;
}