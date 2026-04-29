#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	//1.利用重载符号 “  =  ”来做赋值操作（也是最常用的）
	string s1;
	s1 = "hello,world";
	cout << s1 << endl;
	
	string s2;
	s2 = s1;//这里的 s1 = s2  很像“默认拷贝构造”，但其实不是，而是 s2 operator=(s1) 这才是原型，很明显，= 重载！！！
	cout << s2 << endl;

	//2.利用 string类 的“成员函数” assign() 来赋值
	//(1)直接传入字符串
	string s3;
	s3.assign("hello");
	cout << s3 << endl;
	//(2)直接传入字符串，和数字--- 表示，将字符串的前n个字符赋值给 s4
	string s4;
	s4.assign("hello", 3);
	cout << s4 << endl;
	//但是倘若传入的是一个 string 类型的 对象呢？
	string s5;
	s5.assign(s3, 2);
	cout << s5 << endl;//它传入的并不是前2个，而是除了前2个的所有字符都写进去，所以 s5="llo" 而不是 "he"
	//(3)直接传入string 对象
	string s6;
	s6.assign(s5);//效果类似于“拷贝构造函数”&&“ = 的运算符重载”
	cout << s6 << endl;
	//(4)用assign() 函数传进 n 个 字符 
	string s7;
	s7.assign(7, 'e');//这与 string 类中的“有参构造函数”效果一致，用法也一直---先写个数，后写字符
	cout << s7 << endl;

	system("pause");
	return 0;
}