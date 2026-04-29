#include <iostream>
using namespace std;
//1.定义函数模板
template<typename T>//这里也可以写为：：：：：  template<class T> 其中，T 为类型名是自定义的，所以可以用任何字母表示B也行
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	// 交换连个变量的值，这个函数还记得吧？-- 那么（交换不同类型变量--int--double）的函数主体基本一致吧！
	// 可是如果有很多的变量需要交换，难道每个不同类型函数都要重写一遍吗？-- 显然是繁琐的，那么该如何简化这一步骤？
	// 当然，你可以写一个类（class），但是内容还是要你重复写，显然不行了。
	// 那么这时候就可以写一个“模板”，通用的模板，只需要一个就可以

	int a = 10;
	int b = 20;
	//1.这里是调用函数模板的第一种写法--- 自动识别法 --- 但是不知道a,b 类型不相同会如何？
	myswap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl << endl;
	//2.这里是第二种写法-- 手动传参法 <int>、<double> 都可以，【尤其是 C++ 可以有程序员自己定义数据类型】
	myswap<int>(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl << endl;


	//3.这是C++内置的交换函数，写在头文件 <iostream>中，可以调用
	swap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;


	//4.上述这几种函数，传入的都必须是“同一个数据类型的数据”-- 当然，swap()函数是固定的，但是
	// 
	// .模板函数-- 应该有办法同时传不同类型的数据
	system("pause");
	return 0;
}
    //5.模板特点：（1）提高函数"复用性"，
	// 将“类型参数化”--- 理解为：将 T 作为类型的 “形参”，具体说明类型，
	// 得依靠上述两种方式去告诉编译器，--即为：：传入“类型参数”
    // （2）template<typename || calss T>