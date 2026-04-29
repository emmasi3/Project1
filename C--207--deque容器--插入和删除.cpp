#include <bits/stdc++.h>
#include <iostream>
using namespace std;



void test01()
{
	//1.插入 push_back()  尾插
	// .头插 push_front()
	// .pop_back()  ,,  pop_front() 头部操作
	// 
	//2.
	//insert(pos,elem)
	//insert(pos,begin(),end())   --  可以在 第 0 个位置，插入 一段区间 “begin(),end()”!!! 这是和 vector 不同的地方
	//insert(pos,n,elem)

	//3.
	//erase(pos)
	//erase(begin(),end()) --- 这里的参数必须为--迭代器，当然，你可以先创建一个 迭代器（指针），然后++ 挪动指向后，在
	//clear() -- 清空操作      添加参数也可以！！！
}

int main()
{
	test01();

	system("pause");
	return 0;
}