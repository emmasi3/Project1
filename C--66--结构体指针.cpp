#include <iostream>
using namespace std;
#include <string>

struct Student {
	string name;
	int age;
	int score;
};

int main()
{
	Student s = { "张三",18,100 };
	Student* p = &s;
	// 1. 结构体指针实际上就是 类型为结构体，可以这样记，也可以这样去理解，但本质不是这样的
	// 2. 怎样访问指向的 s 并写入一些数据？
	string a = p->name;
	int b = p->age;
	int c = p->score;
	cout << a << " " << b << " " << c << " " << endl;
	// . -> 是一个“提取”符号，提取出 指针p 所指向的 结构体变量的 “属性”， p->age 这个表达式的返回值为：属性值

	system("pause");
	return 0;
}