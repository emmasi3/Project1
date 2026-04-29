#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	//1.字符串获取-- substr()内置函数--成员函数
	string s1 = "hello,world";
	string s11 = s1.substr(0, 7);//截取从 0 下标所在字符开始，长度为7的字符串
	cout << s11 << endl;         //并且，substr() 函数返回值类型为-- "string" 

	//2.有非常大的实用价值
	string str = "张三@qq.com";
	//现在，我想设计一个算法-- 可以提取邮件的发送者的名字--张三
	int a = str.find('@');
	string strr = str.substr(0, a);
	cout << strr << endl;
	//所以，一切为了实际运用而产生！要注重每一个知识在实际当中的运用！

	system("pause");
	return 0;
}