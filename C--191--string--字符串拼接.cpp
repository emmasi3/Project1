#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//1.利用重载 += 符号拼接字符串
	//(1)
	string s1 = "I";
	s1 += " Love";
	cout << s1 << endl;
	//(2)
	string s2 = " Play Game";
	s1 += s2;
	cout << s1 << endl;

	//2.利用成员函数（内置）append() 拼接字符
	string s3;
	s3.append("I Love");
	cout << s3 << endl;
	//基本功能都和 运算符  +=  重载一毛一样，但是，想要进行精确的拼接，就需要这个函数了
	//(1)只拼接 s2 的前5个字符，必须用append() 函数，+= 不能实现
	s3.append(s2, 5);
	cout << s3 << endl;
	//(2)字符串的前 4个字符也可以
	s3.append(" DNF LOL", 4);
	cout << s3 << endl;
	//(3)拼接 一段区间的也可以
	s3.append(",are you?", 0, 8);//这个要单独讲一下：0 -- 开始位置的“下标”切记，下标的开始位置为：0
	cout << s3 << endl;          //  8  --这个不是下标位置，而是从 0 位开始，向后拼接的 “位数”，这个和其他函数不一样
	
}

int main()
{
	test01();

	system("pause");
	return 0;
}