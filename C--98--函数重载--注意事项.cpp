#include <iostream>
using namespace std;

void f(int& a) {

}
void f(const int& a) {

}
//1. 此时，是允许存在的 因为 const int&    -----     与     ---  int&   不是一个类型的参数，，，引用做重载条件
void ff(int a, int b = 20) {

}
void ff(int a) {

}

int main()
{
	ff(10, 20);
	//2. 这样的输入俩数据是正确的会调用11 行的 ff(),可是一旦有  ff(10); 就会报错，因为电脑不知道该执行哪个函数？
	// . 而这就是函数重载的 重要判断依据----电脑是否能够区分 该执行哪个程序？
	// . 用11/14 俩行代码写重载，也没有错，但是写程序调用函数时，特别容易出错，所以
	// . --- 参数默认值，做重载条件

	system("pause");
	return 0;
}