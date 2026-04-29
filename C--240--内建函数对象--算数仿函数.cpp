#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void test01()
{
	negate<int>n;//取反仿函数，就是“相反数”，这个不知道有什么用？

	cout << n(50) << endl;

	int a = 10;
	int* b = &a;
	int** c = &b;
	cout << **c<<"   " << a << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}