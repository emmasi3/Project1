#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//1.vector容器 因为与数组非常相似，所以也称为“单端数组”！=“数组”
//2.传统数组，就像一个马克杯，他的被子容量已经定型（指定了最大空间后），不可能再次改变
// .但是 vector 这个特殊的“单端数组”不一样，它允许这个马克杯的容量不停的改变，
// .就像一个气球，它的最大容量点，其实就是系统还有多少可用内存，所以一般来说，容量就是可以随便变化的！！！
// .也称为：：“ 动态扩展 ”
//3.动态扩展：：不是在已有的vector 后面的连续空间继续追加数据，而是在内存空间中，寻找一块更大的空间，
// .将“初始数据以及新增数据”全部都拷贝到 “新空间”，然后“自动释放”原有的空间
//
//4.vector 的迭代器是-- 随机访问的迭代器---功能最为“强悍”的迭代器

void myprintf(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
}

void test01()
{
	//1.默认无参构造函数
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//2.有参构造函数
	//(1)区间形式
	vector<int>v2(v1.begin(), v1.end());//这里是左开右闭的 [ v1.begin(),v1.end() ) 因为：v1.end() 指向的是最后一位的下一位
	myprintf(v2);
	cout << endl;

	//(2)个数
	vector<int>v3(10, 100);//这个是传入 10 个 100进入“单端数组”
	myprintf(v3);
	cout << endl;

	//3.默认拷贝构造函数
	vector<int>v4(v3);
	myprintf(v4);
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}