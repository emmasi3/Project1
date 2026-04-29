#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
 *  string 的本质是一个“类”，string s1;--可以调用默认构造函数，其内部有一个“属性”-- char*  
 *  而在C语言中，char* 就是一个指针，可以被当作字符串使用，
 *  那么在 c++ 内，string 也是如此，它的底部放了一个char* 的指针，用来接收外部传进来的“字符串”或者“字符”
 */

int main()
{
	//1.默认无参构造函数
	string s1;
	//2.有参构造函数
	const char* str = "hello,world";
	string s2(str);
	cout << s2 << endl;
	//3.默认拷贝构造函数
	string s3(s2);
	cout << s3 << endl;

	//4.使用 n 个字符 初始化string 的对象
	string s4(15, 'r');//这是最新知道的一个用法，当然本质其实是--自定义--有参构造函数
	cout << s4 << endl;


	system("pause");
	return 0;
}