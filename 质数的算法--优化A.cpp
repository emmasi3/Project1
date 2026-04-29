#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//1.这个思路主要是 sqrt(n) ,因为你从 2 遍历到 n-1,在 2 + 到sqrt(n)之前，所有的
// .[2,n-1] 区间内的“整数”都已经组合过一遍了，所以，
// .> sqrt(n) 后的部分，全部在重复判断，这是没有必要的，所以，大大减少了循环次数（但是还是不够快）

int main()
{
	int n;
	cin >> n;
	int judge = 0;

	for (int i = 2; i < n + 1; i++)
	{
		if (i == 2)
		{
			cout << 2 ;
			continue;
		}

		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				judge++;
				break;
			}
		}

		if (judge == 0 )//如果是质数
		{
			cout << " " << i;
		}
		judge = 0;
	}
	cout << endl;

	system("pause");
	return 0;
}