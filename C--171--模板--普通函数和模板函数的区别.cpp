#include <iostream>
using namespace std;

int add1(int a, int b)
{
	return a + b;
}

template<typename T>
T add2(int a,int b)
{
	return a + b;
}

int main()
{
	int a = 10;
	char b = 'b';
	cout << add1(a, b) << endl;//1.如你所见：普通函数add1()需要传入两个 int 类型的参数 但是传入 char b 也并未报错，很显然
	//编译器自动将 char -> int ，所以未报错！！！

	//2.cout << add2(a, b); 这句代码明显报错了，因为：编译器再调用“模板函数”时，不知道哪个类型（int \ char）是你想要的
	//                     所以会报错，也就是没有发生“隐式类型转换”
	cout << add2<int>(a, b) << endl;
	//3.这时候就不会报错了，因为你已经指定了 <int> 类型，所以编译器会自动“隐式类型转换”

	//4.总结（区别）：（1）普通函数-》隐式转换法
	// .              （2）模板函数：没有明确指定 <int> 就不能够--》隐式转换法
	system("pause");
	return 0;
}