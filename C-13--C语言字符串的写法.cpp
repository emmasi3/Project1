#include <iostream>
using namespace std;
#include <string>

int main()
{
	char str[] = "hello world";
	cout << str << endl;
	//1. 这是“C语言”风格的写法，在c++中也可以用
	string str1 = "hello world";
	cout << str1 << endl;
	//2. 这是“c++”风格的写法：string 你可以理解为--“字符串”类型
	// . 但是在用string 的时候必须要引用头文件---<string> 库

	system("pause");
	return 0;
}