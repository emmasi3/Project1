#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void test01()
{
	//1.字符串查找--find()--返回值类型为 int 即为 字符串第一个字符所在位置的“下标”
	string str;
	str = "hello,world";
	int a = str.find("llo");//find("llo",0) -- 这和这一行代码是等效的，因为find() 函数在定义的时候，int pom=0,是一个默认值
	cout << a << endl;      //所以你传不传都无所谓，传了会改变 0 这个初始值

	a = str.find('e');
	cout << a << endl;

	a = str.find("o,ww", 1, 3);//这个意思是 查找 从str 的第 1 位开始查找 "o,ww" 前 3 个字符串第一次出现的位置
	cout << a << endl; //o,ww 这个字符串显然没有在 str 中 ，所以1，4的话，会返回 -1 的值，意思是“没找到”
	                   //而如果是 1，3 的话，就会返回 4 的正确下标，因为 o,w 在str 中存在

	//2.字符串查找--rfind()--返回值类型 -- int -- 从右往左开始查，返回“需要查找字符串”首位所在的“下标”，
	//返回值 的大小和种类 都和 find() 一致
	//区别：rfind() 与 find() 查找顺序不一样！

	//3.字符串替换--replace()
	str.replace(0, str.length(), "world,hello");
	cout << str << endl;
	//表示————从 0 下标所在位置开始，往后str.length()个字符被“替换”为"world,hello"
	str.replace(1, 2, "SBSBSB");
	cout << str << endl;
	//4.你觉得结果是多少呢？是 "wSBld,hello" 还是 "wSBSBSBld,hello"？
	//.会是 "wSBSBSBld,hello",而且直接替换掉，"or"

}

int main()
{
	test01();

	system("pause");
	return 0;
}