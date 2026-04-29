#include <iostream>
using namespace std;

int main()
{ 
	int a = 10;
	int& b = a;
	cout << "a=" << b << endl;

	int * const p = &a;
	cout << "a=" << *p << endl;
	//1. 引用的本质是-- 指针常量 -
	//-  int* const p= &a; 也就是 指向不可以改变的指针，
	//-  计算机中实现的原理是： 执行 int& b = a; 时，“内部”实际上会执行 int * const b = &a; 
	//-  使用 b 引用时，“内部”：： 将a所在空间的值，直接读出给  b  

	//多学200多节课，终于是让我找到一种我认为 关于指针常量的合适解释了！ 请看 “二叉树--遍历--栈的方式”
	//核心：每次调用 指针常量 时，都会提前执行 一句代码 ： p = *a; 其中 p 为别名，a为真实数据，也就是迭代更新
	//    ：使得人们看起来 p 就是 a 本身，但其实就是另一个变量 --> 一个始终和本体 a 拥有相同内容的变量（地址特么都一样）
	system("pause");
	return 0;
}