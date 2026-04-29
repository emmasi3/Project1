#include <iostream>
using namespace std;

// 成员变量 和成员函数 分开储存
class Person
{
public:
	int a;
	static int b;
	void f() {};
	static void f1() {};
};
int Person::b = 0;

void test01() 
{
	Person p;
	cout << sizeof(p) << endl;
	// 1. 在 p 中属性全无的时候，p --对象 的大小为 “1” 字节，原因：这是自动分配的，是为了避免其他的类占用和p
	//  . 一样的空间，所以 即使 Person 类 为空实现，也会分配 1 字节的空间

	// 2. 在加入 int a; 之后 占用了 4 字节，说明---         “成员变量”在 “类的对象上”
	// 3. 在加入 static int b; 之后，占用了 4 字节，说明--  “静态成员变量”不在“类的对象上”
	// 4. 在加入 两个函数（静态与非静态）之后，依旧时 4 字节，所以 没在 “类的对象上”；

	// 5. 只有 成员变量 在 “类的对象上”，其余都不在！！！

}

int main()
{
	test01();

	system("pause");
	return 0;
}