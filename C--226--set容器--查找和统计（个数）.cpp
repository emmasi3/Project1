#include <iostream>
#include <string>
#include <set>
using namespace std;

void myprintf(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

class Person
{
public:
	Person(std::string name, int age) : 
		m_name(name),m_age(age)
	{
		std::cout << "Person 构造开始了！" << std::endl;
	}

	bool operator<(const Person& v) const
	{
		return m_name < v.m_name;
	}

	std::string m_name;
	int m_age;
};

void test01()
{
	set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);

	myprintf(s);

	//1.查找
	set<int>::iterator it = s.find(50);//find() 内置函数的返回值类型为 -- 迭代器，查找元素的迭代器
	cout << *it << endl;               //如果没找到，则会返回 s.end() 这个迭代器
	//那么利用这个特性，就可以判断 50 是否在 set 容器中

	//2.统计（指定元素个数）
	int num = s.count(200);  //返回值类型为 int ，但是在 set 容器中，结果只有 0,1, 因为：set 容器元素具有唯一性
	cout << num << endl;     //所以这个方法主要用在 multiset 容器里面，这个容器和 set 容器唯一的区别就是
	                         //数据储存没有 “唯一性”
}

static void test02()
{
	std::set<Person> s;
	s.insert(Person("1", 17));
	s.insert(Person("2", 18));
	s.insert(Person("0", 18));
	s.insert(Person("wu", 18));

	auto a = s.find(Person("1", 20));
	std::cout << a->m_name <<  a->m_age << std::endl;
}

/*
* 1、现在实验猜测：set::find(i)，是通过-----  !comp(a,b) && !comp(b,a) == true  -----来判断 i 是否在 set 中的？
*	所以当set中存放的是自定义类型时，必须重载 < 号运算符才行，否则报错
* 
* 2、在重载 < 函数中，具体用自定义数据类型的 哪一个成员变量作为判断标准，由你自己决定，如果你直接用所有的 变量属性作为判断标准，
*	那就和直接判断 两个 Person 实例化对象是否完全一致了，也就是  a == b 的行为，但是一般来说，在我的服务器项目中，
*	logger::name 是在 < 重载中作为判断标准，查看是否存在这样的 一个 logger，以此来判断是否需要“新增、删除”相应的 logger
*	而通过 logger 的自定义 == 重载运算符，来进一步判断，find 到的 logger 是否存在 其他成员属性的修改，如果发生了变化，
*	就要求 修改该 logger，嗯嗯大概是这个意思
* 
* 3、几乎所有的容器，set的很多东西，都是用模板来做的，所以，所有的定义实现，都必须在编译阶段完成
*	当我注释掉 test02() 中的 set<Person> 时，无论我对Person::operator<() 函数的参数、修饰类型做什么修改，都不会报错，
*	但是当 set<Person> 出现时，如果那两个 const 少一个，就会直接报错，因为 set::< 的这个比较函数，需要接触你重载的函数来进行
*	必须要满足 set 中的 < 重载运算符函数要求
* 
*/

int main()
{
	//test01();
	test02();

	return 0;
}