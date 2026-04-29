#include <iostream>
using namespace std;
#include <string>

template<class nametype,class agetype>
class Person
{
public:
	Person(nametype name, agetype age)//1.这样就是一个“类模板”了，成员变量或者函数，他们的类型 都可以用 T 或其他的来代替
	{
		this->name = name;
		this->age = age;
	}
	nametype name;
	agetype age;
};

int main()
{
	Person<string, int>p1("张三", 10);
	//2.在使用类模板来创建具体类对象的时候，必须要有“类模板参数列表”以用来指定“模板的参数”
	cout << p1.age << "   " << p1.name << endl;

	system("pause");
	return 0;
}