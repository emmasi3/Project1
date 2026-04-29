#include <iostream>
#include <string>
#include <memory>

class Person
{
public:
	typedef std::shared_ptr<Person> ptr;

public:

	Person(std::string name, int age)
		:m_name(name), m_age(age)
	{
		std::cout << "Person 有参构造函数\n";
	}

	bool operator<(const Person& p)
	{
		return m_age < p.m_age;
	}

private:
	std::string m_name;
	int m_age;
};


int main(int argc, char* argv[])
{
	/*
	* 1、你可以看见，你个普通的类 Person，
	*	现在问：operator<() 重载运算符函数中，p 算不算外部对象？
	*		假设 Person a,b; 两个实例化对象，a < b;
	*		现在执行 < 重载函数的对象是 a，不是b，这时候，b就是外部对象，
	*		并且你可以看见，在重载 < 函数中，p.m_age ，这个 p 是一个外部对象
	*		但是现在在外部，访问了 p 的私有成员，是不是错了呢？
	*	答案：没有错，如果 C++ 标准，不允许这样做的话，会多很多的麻烦，不仅仅影响单纯的
	*	同类对象之间的 “符号运算”，还会影响很多东西，并且这样子设计，也不会因为权限的影响，
	*	增加额外的工作量，至于安全问题，和这个也没有太大的关系，反而是加上这层 “保护”，会影响
	*	工作的效率，或者是逻辑上的不可行，总之：
	*	同类对象之间，访问不受权限影响
	* 
	* 
	*/

	return 0;
}