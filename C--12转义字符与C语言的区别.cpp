#include <iostream>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	cout << "hello world\n";
	//1. \n ,这和C语言中的作用一样，都是在要输出的语句后面跟着，但是区别是有没有endl,endl==\n也具有换行的作用！！

	cout << "\\"<<endl;
	//2. 像这样只会打印出来一个  “\”，并且如果只写一个\，那么就会报错，因为“\”是特殊的!!!,必须要两个
	cout << "000\thello world" << endl;
	cout << "1111\thello world" << endl;
	cout << "22222222\thello world" << endl;
	//3. \t,
	// 这和C语言中的也差不多，只不过这个用来控制“终端”内的打印结果“对齐”--也就是不足8个时，留下 8-（个数）--空格；
	// . 但是一旦字符数 >=8 个，就会直接再次来 4 个字符空格
	system("pause");
	return 0;
}