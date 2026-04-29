#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m = 0;
	cin >> m;
	int mm = m;
	double sum =0 ;
	//1.整除(发了多少次) n-1
	int n = 0;
	for (int i = 1; m > 0; i++)
	{
		m -= i ;
		n++;
	}
	//计算整数部分
	for (int i = 1; i < n; i++)
	{
		sum += i * (i / 10.0);
	}
	//2.剩余部分
	int k = mm - ((n-1) * (n) / 2);//剩余天数
	sum += k * ((n ) / 10.0);

	printf("%.2f", sum);

	return 0;
}