#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 0;

	int m = 0;

	if (n < 2)
	{
		return 0;
	}
	else if (n > 2)
	{
		cout << 2 << " ";
	}
	else if (n == 2)
	{
		cout << 2 << endl;
	}
	//
	for (int i = 2; i < n+1; i++)
	{
		if (i == 2)
		{
			continue;
		}

		for (int j = 2; j < i; j++)
		{
			if (i % j != 0)
			{
				continue;
			}
			else
			{
				m = 1;
				break;
			}
		}


		if (m == 0)
		{
			num++;
			if (num == 1)
			{
				cout << i;
			}
			else
			{
				cout << " " << i;
			}
		}
		else
		{
			m = 0;
		}

	}


	system("pause");
	return 0;
}