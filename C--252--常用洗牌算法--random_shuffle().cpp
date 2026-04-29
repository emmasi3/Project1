#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void myprintf(int v)
{
	cout << v << " ";
}

void test01()
{
	vector<int>v;
	for (int i = 0; i < 9; i++)
	{
		v.push_back(i);
	}
	cout << "洗牌前：" << endl;
	for_each(v.begin(), v.end(), myprintf);
	cout << endl;

	cout << "洗牌后：" << endl;
	random_shuffle(v.begin(), v.end());//1.棋牌类游戏必有的 函数，底层有 rand() 的影子，所有，得定义随机数种子！！！
	for_each(v.begin(), v.end(), myprintf);
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));//2. rand() , random_shuffle() 必须有“随机数种子”
	test01();

	system("pause");
	return 0;
}