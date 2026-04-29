#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, t;
	cin >> x >> y; //当 t == 0 时，y为最大公约数

	while (y > 0)
	{
		t = x % y;
		if (t == 0)
		{
			break;
		}
		x = y;
		y = t;
	}

	if (y != 1)
	{
		cout << y;
	}
	else
	{
		cout << "没有最大公约数" << endl;
	}


	system("pause");
	return 0;
}