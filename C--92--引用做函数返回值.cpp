#include <iostream>
using namespace std;

int& f() 
{
 //1. int a = 10;  这样写，是不对的，因为，a 作为“局部变量”，会在 f()执行完毕后，清空内存，而"引用"和 a 代表同一个
 //  空间，所以在 堆区内无法接收 a=10 的结果

	static int a = 10;
//2. static 是“修饰”和const 是一类的，与 new 差不多，作用：： 将变量或者其他的东西，定义为 “全局变量”，也就是头文件
// 的下面，
	return a;
}

int main()
{
	int a = f();
	cout << "a=" << a << endl;
	// 3. 因为 a 是在“堆区”对“栈区”别名，所以对 a 做改动，f() 里面的 a  的值也会变化

	system("pause");
	return 0;
}