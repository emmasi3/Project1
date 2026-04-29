#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	vector<int>v;
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i);
	}
	cout << "大小：" << v.size() << endl;
	cout << "容量：" << v.capacity() << endl;
	sort(&v[0], &v[10] + 1, greater<int>()); //1.这里直接写 v[10] 因为“左闭右开”，不能排到 10 ，所以不能达到目的！
	                                  //.但是若直接写 v[11]，这个东西不存在，所以会报错。
	for (int i = 0; i < v.size(); i++)//.但是：vector 容器的储存空间是“连续的”，
	{                                 //.所以：v.end() 指向的空间(地址) == &v[10] + 1;   点个赞！！！
		cout << v[i] << endl;
	}

	//2.对于自定义数据类型--排序，哎···和前面一样，不写了，累！
}

int main()
{
	test01();

	system("pause");
	return 0;
}