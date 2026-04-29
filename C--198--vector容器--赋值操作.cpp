#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void myprintf(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//1.operator=  重载 = 进行赋值
	vector<int>v2;
	v2 = v1;
	myprintf(v2);
	cout << endl;

	//2.利用 assign()-- 赋值函数（内置/成员函数）赋值
	//(1)区间
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());//begin 和 end 同时出现， [ , ) 区间
	myprintf(v3);
	cout << endl;
	//(2)赋值 n 个 数据（相同）
	v3.assign(10, 100);
	myprintf(v3);
	cout << endl;

	//3.注意：赋值操作，不等于，构造函数的操作！！！，虽然不知道具体有什么区别？，但似乎好像结果上一样！！！
}

int main()
{
	test01();

	system("pause");
	return 0;
}