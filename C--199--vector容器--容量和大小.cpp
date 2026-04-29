#include <bits/stdc++.h>
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
	//1.判断是否为空
	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
	}
	myprintf(v1);
	cout << endl;

	//2.容器容量
	cout << "v1的容量为：" << v1.capacity() << endl;//容量 >= 大小，因为此时还有 3 个位置空着，而大小只有 10
	cout << "v1的大小为：" << v1.size() << endl;
	
	//3.重新指定大小
	v1.resize(15,2); //如果你指定的大小 > 10（原有的“大小”），那么剩下的没填充的位置就会"默认"用“0”来代替
	myprintf(v1);    //当然你也可以 v1.resize(15,100) 使没填充的位置 全部为 100
	cout << endl;
	
	v1.resize(5);
	myprintf(v1);//如果你指定的大小 < 10,那么原有的超额的数据将会被“删除”
	cout << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}