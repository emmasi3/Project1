#include <iostream>
using namespace std;

double f_throw_const_char(int a, int b)
{
	if (b == 0)
	{
		throw "除数不能为0！";
		return -1;
	}

	return a * 1.0 / b;
}

double f_throw_int(int a, int b)
{
	if (b == 0)
	{
		throw -1;
		return -1;
	}

	return a * 1.0 / b;
}

void foo()
{
	cout << "函数指针被抛出" << endl;
}

int main()
{
	//首先，异常捕获和抛出机制，一共是三个步骤
	//  try{}  catch{}  throw

	//一、throw，抛出机制
	//1、throw可以抛出 const char* ，字符串常量
	try
	{
		f_throw_const_char(5, 0);
	}
	catch(const char* e)
	{
		cout << e << endl;
	}
	
	//2、可以抛出 int，double，很多类型，几乎所有类型
	try
	{
		f_throw_int(5, 0);
	}
	catch (int e)
	{
		cout << e << endl;
	}

	//3、函数指针，类···几乎所有类型，嗯嗯，都可以被抛出
	try
	{
		throw foo;
	}
	catch (void(*a)()) // 返回类型 (*函数指针名)(参数列表)
	{
		a();
	}

	//
	try
	{
		f_throw_const_char(5, 0);
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}