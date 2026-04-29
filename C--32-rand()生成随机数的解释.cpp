#include <iostream>
using namespace std;

int main()
{
	//1. 生成一个随机数（不规定范围的）
	int a = rand();
	cout << a << endl;
	//2. 生成一个（有固定范围的）
	int b = rand() % 100;
	cout << b << endl;
	// .这个的范围是：[0,99],因为：余数不能大于除数（100），不小于0（ >=0 ）
	// .所以采用这样的方式来控制，随机数的 “范围”
	system("pause");
	return 0;
}