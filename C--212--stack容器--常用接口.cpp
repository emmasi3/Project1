#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	//1.常用接口-- 拷贝构造 -- 默认无参构造 -- =重载运算符 -- 
	//2.数据存取：push() -- 存
	//3.          pop()  -- 删除
	//4.          top()  -- 取       -- 最顶部，而且只能从最顶部取 ！！！
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	//5. empty() 内置判断 stack 是否为空？--- “取出所有的数据”-- 基本操作

	cout << s.size() << endl;

	while (!s.empty())
	{
		cout << s.top() << "  ";//返回“最顶部元素”-- 直接是返回对象本身，而不是“迭代器”、“地址”
		s.pop();   //这个是“出栈”-- 也就是 “删除”吧
	}
	cout << endl;
	
	//6. size() 内置函数 返回“大小”
	cout << s.size() << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}