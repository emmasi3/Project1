#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)//ÐÐ
	{
		for (int j = 1; j <= i; j++)
		{
			cout << '*';
		}
		for (int j = 1; j <= (2 * n) - (i * 2); j++)
		{
			cout << ' ';
		}
		for (int j = 1; j <= i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}



	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{




	return 0;
}