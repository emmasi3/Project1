#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	cout << "" << endl;

	cin >> a >> b >> c;
	//1. 此处需要注意和C语言中scanf()不同的是，需要这样写，同时输入多个变量的值！！！！

	if (a >= b && a >= c) {
		max = a;
		cout << "最重的小猪是：a" << endl;
	}
	else if (b >= c) {
		max = b;
		cout << "最重的小猪是：b" << endl;
	}
	else {
		max = c;
		cout << "最重的小猪是：c" << endl;
	}


	system("pause");
	return 0;
}