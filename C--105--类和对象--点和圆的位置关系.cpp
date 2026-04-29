#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
};

class Circle
{

public:
	//圆的方程（标准式）
	//  (x - x0)(x - x0) + (y - y0)(y - y0) = 1;
	void judge_relation(Point& p1)
	{
		int t = x0 - p1.x;
		int T = y0 - p1.y;
		int M = ( t*t +T*T == r*r );
		if (M==1) {
			cout << "点p1在圆c1上" << endl;
		}
		else {
			if (t * t + T * T > r*r )
			{
				cout << "点p1在圆c1外" << endl;
			}
			else
			{
				cout << "点p1在圆c1内" << endl;
			}
		}
		
	}

public:
	//半径
	int r;
	//横坐标
	int x0;
	//纵坐标
	int y0;
};

int main()
{
	Point p1;
	cout << "点p1的横坐标：" << endl;  cin >> p1.x;
	cout << "点p1的纵坐标：" << endl;  cin >> p1.y;

	Circle c1;
	cout << "圆c1的半径：" << endl; cin >> c1.r;
	cout << "圆c1圆心的横坐标：" << endl; cin >> c1.x0;
	cout << "圆c1圆心的纵坐标：" << endl; cin >> c1.y0;

	c1.judge_relation(p1);

	system("pause");
	return 0;
}