#include <iostream>
using namespace std;

class basecase
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册···（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图···（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++···（公共分类列表）" << endl;
	}
}; // 1. 这是一个公共部分，里面的内容，是每一个“类”都有的，如果都写一份相同的代码，太浪费空间、时间了--于是
   //  . 就有了“继承”

class Java :public basecase// 2. 继承的基本形式就这样，我感觉，将 : 读作“继承”会好理解很多，而public 则会使继承更细节
{
	void content()
	{
		cout << "Java精品课程视频" << endl;
	}
};

int main()
{
	// 3. 子类---派生类--  Java
	// 4. 父类---基类  --  basecase

	system("pause");
	return 0;
}