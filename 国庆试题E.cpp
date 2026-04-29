#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int n = 0;
	int sum = 0;
	for (int i = 0; i<10000;i++)
	{
		for (int j = 0; j<10000; j++)
		{
			sum = i * a + j * b;
			if (sum == c)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	system("pause");
	return 0;
}