#include <iostream>
using namespace std;

class Person
{
public:
	static int f() //1. 静态成员函数--- 程序共享一个函数 --- “静态成员函数”只能访问“静态成员属性”
	{
		cout << a << endl;
	 // cout << b=4 << endl;  ,这是会报错的，原因：如果可以访问，那么，所有的对象，都可以调用 b 并且对其进行修改
		// 这就有一个问题，访问 b 本来要通过 , p.b ,但是现在，运行函数 f()里面只有 b=4,并且，每一个对象
		// 都能调用f()
		// 都会得到 b=4 ，那么
		// 它是谁的属性呢？这是不知道的
	}
	static int a;
	int b=4;
};
int Person::a = 0;

int main()
{


	system("pause");
	return 0;
}