#include <bits/stdc++.h>
using namespace std;

int main()
{
	//int n,nn; char a;
	//cin >> n >> a;
	//int line=0;
	//nn = n;
	////1.计算最大行数 line
	//for (int i = 1; n > 0; i += 2)
	//{
	//	n -= i;
	//	line++;
	//}

	//n = nn;
	////2.

	//for (int i = 1; i <= n; i++)
	//{

	//}
	int n;
	cin >> n;
	//1.上半部分
	for (int i = 1; i <= (n-1)/2; i++)
	{
		//每一行字符数
		for (int j = 1; j <= 10; j++)
		{
			cout << '*';
		}
		cout << endl;
		//每一行空格
		for (int j = 1; j <= i ; j++)
		{
			cout << ' ';
		}
	}
	//2.中间
	for (int j = 1; j <= 10; j++)
	{
		cout << '*';
	}
	cout << endl;

	//3.下
	for(int i = (n - 1) / 2; i >=1; i--)
	{
		//每一行空格
		for (int j = 1; j <= i-1; j++)
		{
			cout << ' ';
		}
		//每一行字符数
		for (int j = 1; j <= 10; j++)
		{
			cout << '*';
		}
		if (i > 1)
		{
			cout << endl;
		}

	}



	return 0;
}