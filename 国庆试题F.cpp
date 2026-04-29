#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n % 4 == 0 && n%100!=0)
	{
		cout << "yes" << endl;
	}
	else if(n%100==0 && n%400==0)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	system("pause");
	return 0;
}