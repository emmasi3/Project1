#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 0;
	int money;

	for (int i = 0; i < 41; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 201; k++)
			{
				money = i * 5 + j * 2 + k * 1;
				if (money == n)
				{
					num++;
				}
			}
		}
	}
	cout << num << endl;

	system("pause");
	return 0;
}