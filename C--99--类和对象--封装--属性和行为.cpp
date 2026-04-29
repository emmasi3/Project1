#include <iostream>
using namespace std;

const double pai = 3.14;

class Circle
{
	//1. 访问权限
public:
	//2. 属性
	// 
	// . 半径
	int r;
	//3. 行为
	// 
	// . 计算周长C
	double Perimeter() {
		return 2 * pai * r;
	}
};
//  到此为止，创建了一个“圆类”，但是并没有创建“对象圆”

int main()
{
	Circle c1;
	//4. 创建“对象”，也被称为，“实例化”
	// 如同结构体一般，Circle 作为类的名字，也可以理解为，c1 的类型，都是通过 . 来访问里面的东西的

	c1.r = 10;
	cout<<"圆c1的周长："<< c1.Perimeter() <<endl;

	system("pause");
	return 0;
}