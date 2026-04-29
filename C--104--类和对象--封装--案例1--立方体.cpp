#include <iostream>
using namespace std;

class Cube
{
public:
	int area()// 面积
	{
		return (a * b + a * h + b * h) * 2;
	}
	int volume() // 体积
	{
		return a * b * h;
	}
	void cmp(Cube& c3)          //1. 这里采用”引用“作为函数的参数，可以节省空间，因为，直接传进来 Cube c3,相当于
		                        //   复制一份，占用了空间
	{
		if (a == c3.a && b == c3.b && h == c3.h)
		{
			cout << "c1和c3相等" << endl;
		}
		else 
		{
			cout << "c1和c3不相等" << endl;
		}
	}

public:
	int a;
	int b;
	int h;
};

int main()
{
	Cube c1{ 1,2,3 };
	Cube c2{ 7,8,9 };
	Cube c3{ 7,8,9 };

	cout << "c1面积为：" << c1.area() << endl;
	cout << "c2面积为：" << c2.area() << endl;

	cout << "c1体积为：" << c1.volume() << endl;
	cout << "c2体积为：" << c2.volume() << endl;
	//

	c1.cmp(c3);


	system("pause");
	return 0;
}