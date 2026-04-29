#include <iostream>
using namespace std;

class Person
{
public:


	void showage()
	{
		if (this == NULL) {
			goto out;
		}
		else {
			cout << this->age << endl;//1. 运行到这行代码的时候，程序崩了，原因：this 指向的空间实际上就是 NULL，什么
			//   都没有
		}
		// . 想从这儿调用 age 成员变量，不能实现
out:	cout << "this==NULL" << endl;
	}

	void showname()
	{
		cout << "Person 正常运行" << endl; // 2. 但是，这一行会执行，因为空指针可以调用函数，只要你
		                               //  不用 对象 来访问里面的成员变量
	}
	static int b;
	int age=10;
}; int Person::b = 4;

void test01()
{
	Person* p = NULL;
	p->showage();
	p->showname();

	cout << p->b << endl; // 3. 之所以， p.age 不能调用，是因为：age -- 为成员变量，“在类对象上”，

	// 所以 在 p==NULL 时，不能调用，但是，除此以外的其他 -- 成员函数，静态成员变量，静态函数，都不在类对象上
	// 所以都可以调用，唯独 成员变量不行！！！！！！
	//  能 p->b 调用 静态变量 b 就是最好的证明
}

int main()
{
	test01();

	system("pause");
	return 0;
}