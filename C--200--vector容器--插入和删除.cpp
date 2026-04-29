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
	cout << endl;
}

class Person
{

};

void test01()
{
	vector<int>v;
	//1.插入
	  //(1)尾插 -- 在“单端数组”末端插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	  //(2)指定插入 -- 内置函数（成员函数）-- insert() 还有 assign()--这特么是“赋值”操作
	v.insert(v.begin(), 99);   // insert() 的第一个参数必定是一个 “迭代器”-- v.begin() -- 这玩意叫“迭代器”，后面是
	myprintf(v);               //要插入的数据

	v.insert(v.begin(), 3, 1000);//还可以插入 3 个 1000 在“迭代器（类似指针）”指向的位置
	myprintf(v);

	//2.删除
	  //(1)尾删 -- pop_back() 函数
	v.pop_back();    //不需要参数，一次删除一个
	myprintf(v);

	//(2)指定删除 -- erase()
	v.erase(v.begin());  // 和上面类似--需要传一个 “迭代器参数”其实就是指针参数
	myprintf(v);
	  //指定“区间”删除
	v.erase(v.begin(), v.end());
	myprintf(v);
	  //上面这个功能和 clear() 相似，都是“清空”操作
	v.clear();
	myprintf(v);

}

int main()
{
	test01();

	vector<int> mm(10);//创建一个大小为10的容器mm

	vector<Person> mm(10);

	system("pause");
	return 0;
}