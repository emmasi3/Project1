#include <iostream>
#define Day 7
using namespace std;

int main()
{
	const int a = 10;

	cout<<"一周总共有：" <<Day<<"天" << endl;
	cout <<"a=  " << a << "  个" << endl;

	system("pause");
	return 0;
}
/*
  1. 在开头用 #define Day 7   后面没有分号！！！
  2. 和C语言一样 用，const 修饰！！
  3. 关于如何在cout<<<<endl内添加空格，也就是如何在打印结果里面的某处防止空格，直接在""里面加“空格”
*/