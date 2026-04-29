#include <iostream>
using namespace std;

int main()
{
	float a = 3.14;
	cout << "a=" << a << endl;
	//. 此时，结果依旧为3.14 没有错，但是过程为：：先将3.14“转化”为float类型，再打印。。
	float a0 = 3.14f;
	cout << "a=" << a << endl;
	//1.. 此时，结果依旧为3.14,但是这次的3.14直接被认为是float类型，无需转化，      这就是区别
	//2. 计算机会默认小数为--double类型，所以要在3.14后面+f，来注明；
	//3. 计算机自动默认“有效数字”为6位，如果你没有后续的处理，那就是6位，当然还可以再加，只不过现在没学
	// . float/double a=3.1415926f/NULL,结果都为 a = 3.14159,
	// . 有效数字：这和高中物理不一样，凡是有一位数字，就算有效数字，3.14159-- 6 位“有效数字”
	int b = sizeof(a);
	int c = sizeof(float);
	//4. sizeof()函数与C语言别无二致，一样！！

	//科学计数法！！！！
	int t = 3e2;
	cout << "3e2=" << t << endl;
	//5. 3e2==3*10^2;e代表10的次方，2代表“次数”
	int o = 3e-2;
	cout << "3e-2=" << o << endl;
	//6. 3e-2==3*10^-2;为 0.03 

	system("pause");
	return 0;
}