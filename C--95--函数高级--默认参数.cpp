#include <iostream>
using namespace std;

int f1(int a,int b=10) {
	return a + b;
}
int f2(int a, int b=10, int c=10, int d=20) {
	return a + b + c + d;
}

int main()
{
	cout << f1(10) << endl;
	cout << f1(10, 10) << endl;
	cout << f1(10, 20) << endl;
	//1. 函数默认值，直接在定义时 int b=10,就好了。
	// . 默认参数有值后，可以继续 传进数据 f(10,20) 这样，b 的值会以你传进去的为准，并且，可以f(10,20)修改 b 的原值10

	//2. 定义默认形参值的时候，必须统一放在“形参列表”的末尾，也就是从第一个默认值开始，后面的都必须为默认值

	//3. 函数的 “声明” 和 “定义”，对形参的默认值，只能出现一处，（声明有了，定义就不能在此定义形参默认值）
	// 反过来也一样，这样做，是为了避免设计程序时，两者值不一致，导致电脑无法做出准确判断



	system("pause");
	return 0;
}