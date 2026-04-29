#include <iostream>
using namespace std;
//1. 问题：利用 对象名++,使得其属性 ++，分前置和后置，并打印结果
class INT
{

public:
	INT()
	{
		this->a = 10;
	}
	void operator++()//前置递增--默认的
	{
		t = ++this->a;
		cout << "a=" << this->a << "  ++a=" << this->t << endl;
	}
	void operator++(int)//后置递增--需要加 占位参数 int,而且，必须是 int 不能是别的东西
	{
		t = this->a++;
		cout << "a=" << this->a << "  a++=" << this->t << endl;
	}

private:
	int a;
	int t;
};

void test01()
{
	INT num;
	num.operator++();
	++num;
	// 以上两行为前置递增， ++num 为简化结果，但是，好像默认的是只能由前置递增，num++ 会报错
	num.operator++(0);
	num++;

}

void operator++(INT& num) // 这是全局函数--前置递增
{
	
}
void operator++(INT& num, int)// 这是全局函数--后置递增
{

}


int main()
{
	test01();

	system("pause");
	return 0;
}