#include <iostream>
using namespace std;

template<class T>
void func()
{
	cout << "func函数的调用" << endl;
}

int main()
{
	// func(); 如果这样写代码，报错，原因：类型形参T 未确定下来
	func<int>();//1.而这样，<int> 指定 T 的类型就可以了      不管你用不用 T ，都必须指定类型

	//2.必须有一致的 T 的类型
	// 就像C--168 中 我写的那样，如果 a、b 的类型不一致，会报错，

	system("pause");
	return 0;
}// （1）模板函数在调用的时候，T 的类型必须被指定
 // （2）必须传入“一致类型”的数据---- 以便于编译器自己推导出一致的数据类型--然后自动给 T 赋类型