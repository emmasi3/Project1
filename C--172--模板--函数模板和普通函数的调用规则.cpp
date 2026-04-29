#include <iostream>
using namespace std;

void add(int a,int b)
{
	cout << "普通函数的调用" << endl;
}
template<class T>
void add(T a,T b)
{
	cout << "模板函数的调用" << endl;
}

template<class T>
void add(T a, T b, T c)
{
	cout << "函数模板重载" << endl;
}

void test01()
{
	add(0,0);              //1.对于上述的两个重载函数，会优先调用普通函数
	add<>(0, 0);           //2.如左边代码一样， 用 <> 来强制调用“模板函数”
	add(0, 0, 0);          //3.函数模板也可以发生---“重载”
	add('a', 'b');         //4.这行代码会调用 “模板函数”-- 因为：模板函数可以产生更好的匹配！
	                       // .解释（如果调用 普通函数，还要进行 char->int的转换，但是直接用 模板函数，直接可以进行，不用转换
}

int main()
{
	test01();

	system("pause");
	return 0;
}