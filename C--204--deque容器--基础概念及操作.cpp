#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//vector 和 deque 的区别：
//(1)deque 为“双端数组”-- 即为：可以尾插/尾删，也可以 前插/前删 ！！！
//(2)deque 对于 “头部”插入删除 数据的效率比vector快（vector需要移动之后的每一个数据的位置，所以工作量大）
//(3)deque 访问元素的效率比 vector 慢（deque的元素之间不一定是连续的空间储存，而vector是一片“连续的”储存空间）

//deque 内部实现可以看桌面上的截图！，也可以看这一节的课
//1.内部有一个“中控器”和“缓冲区”
//缓冲区：保存真实的数据，每一个缓冲区都有一个“首地址”
//中控器：按顺序保存每一个缓冲区的“首地址”，并且，不是从 0 好位置开始的，而是从中间向两边保存，
//        所以deque 才可以  头部/尾部 -> 保存/删除 ,因为：“它的前面和后面都有可以操作的空间”

void myprintf(const deque<int>& d);

void test01()
{
	//1.各种构造函数
	deque<int>d1;   //默认--无参--构造函数
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myprintf(d1);

	deque<int>d2(d1.begin(), d1.end());//有参--构造函数--  [ , ) 左开右闭
	myprintf(d2);

	deque<int>d3(d2);//默认--拷贝构造函数
	myprintf(d3);

	deque<int>d4(5, 99);//特殊运用 -- 有参构造函数
	myprintf(d4);

}

int main()
{
	test01();

	system("pause");
	return 0;
}

//一般来说，打印函数，都不会改变其中的内容和数据，所以为了保证这一点，加上 const 修饰更好
void myprintf(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}//但是这时候，它的“迭代器的类型”却不和它匹配，因为：“指针”和“常量指针”之间没有适当的转换，所以必须为
// iterator -> const_iterator 才行