#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << "\t" << (*it).second << endl;
	}
}

void test01()
{
	map<int, int>m1;
	//1.插入
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));//一般用这一种！
	m1.insert(map<int, int>::value_type(3, 30));
	m1[4] = 40;                 //这种很容易造成错误，原因：下面

	myprintf(m1);
	cout << m1[5] << endl;//1.此时 容器 m1 中是没有 5 -- key 这个索引的，不会报错，只会给你创建一个 “对组”(5,0),这是默认的
	myprintf(m1);         // .但是你大概率不知道，因为没有报错 ！！！，所以为了避免错误，在插入的时候不采用这个东西

	//2.删除
	m1.erase(4);//删除的是 4 -- key索引到的值 value ,而不是删除值，因为值 vaule 有时候不是唯一的，但是在 map 中key -唯一的
	myprintf(m1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}