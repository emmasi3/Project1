#include <iostream>
using namespace std;
#include <fstream>

int main()
{
	//1.头文件fstream

	//2.创建流对象
	ofstream test;
	
	//3.指定打开方式
	test.open("test.txt", ios::out); //这里的open()以及下面的close() 函数，都在test内，被提前写好，
	                                 //并且，open(要求传入两个参数)，前面：文件路径及文件名，，后面：打开方式，此为写入
	//4.写内容                         //这里 参数 不是要求传两个，而是三个》》可以去看源码，有三个参数，后两个都是默认参数
	test << "姓名：张三" << endl;
	test << "性别：男" << endl;
	test << "年龄：18" << endl;

	//5.关闭文件
	test.close();

	system("pause");
	return 0;
}