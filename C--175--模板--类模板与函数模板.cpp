#include <iostream>
using namespace std;
#include <string>

template<class nametype,class agetype = int >
class Person
{
public:
	Person(nametype name,agetype age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

int main()
{
	// Person p1("张三", 10); 1.如果不添加“模板参数表”那么实例化对象绝对会报错。也就是“类模板”不能自动类型转换
	Person<string, int>p1("张三", 10);
	//. 这才是正确的


	Person<string>p2("李四", 20);
	//2.这里并没有输入int 指明类型，为何不报错呢？
	// .因为：agetype = int 作为“类模板”参数表中的“默认参数”，已经被指明了，当然不用再次传入（当然，再次传入会按照
	// 你“传入的数据类型名”来执行）

	//3.总结：（1）类模板不能 自动类型转换，必须用“模板表”指明
	//        （2）类模板可以 定义 “默认参数”
	//----- 以上两点均为：模板--函数--类-- 之间的区别，所以说，上述两点，函数模板都不能实现
	system("pause");
	return 0;
}