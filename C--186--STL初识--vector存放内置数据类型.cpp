#include <vector>//1.这是万能头文件，但是编译时间特么的慢了一秒？额，好像并没有
#include <iostream>
#include <algorithm>
using namespace std;

void myprintf(int zhi)
{
	cout << zhi << endl;
}

void test01()
{
	//1.创建一个容器vector对象v,并用模板参数列表指定存放内数据类型为：int
	vector<int>v;
	//2.传入数据
	v.push_back(10);//你可以理解为：v 是一个容器“数组”
	v.push_back(20);
	v.push_back(30);
	//3.利用迭代器
	vector<int>::iterator itbegin = v.begin();//这里指向数组第一个元素10，但是保存的绝对不是地址，因为打印不出来
	vector<int>::iterator itend = v.end();//这里指向的是数组最后一的元素的“下一位置”，但是保存的也不是地址，
	//itend 只能是 (*itend) 才可以，这返回值是“值”
	cout << *itbegin << endl << endl;
	//cout << *itend << endl;      这一行可以说明，v.end() 指向的不是30而是30的下一个位置，但是下一个位置编译器并没有给 v 
	//                             分配内存，所以会报错，因为“ * 不能访问那片未分配空间的位置”
	  //4.遍历 vector -- 容器~数组
	  //(1)普通循环:
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl << endl;
	}
	//此时：itbegin 可以类似于地址，itbegin++ 表示位置+1
	//(2)利用内置函数  for_each()
	for_each(v.begin(), v.end(), myprintf);
	//传入起点，终点，函数名，
	//函数 mypeintf() 这是你自己定义的函数，作用在“底层”-- 当你调用函数 for_each() 时，他会在内部有 mypeintf(*it)
	//这一句，看清楚，传进去的是 *it 也就是你输入的值，所以，
	// 你要在自己的函数内部写清楚接下来的行为，
	//并且，写正确需要传进去的“数据类型”-- 这应该和你传进 v 这个容器中的值类型  或者 和 创建 v 时候的<int> 模板表一致
}

int main()
{
	test01();

	system("pause");
	return 0;
}