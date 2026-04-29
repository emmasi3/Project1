#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	multiset<int>m1;
	multiset<int>m2;

	int p;

	for (int i = 0; i < num1; i++)
	{
		cin >> p;
		m1.insert(p);
	}

	////²âÊÔ
	//for (multiset<int>::iterator it1 = m1.begin(); it1 != m1.end(); it1++)
	//{
	//	cout << *it1 << " ";
	//}

	for (int i = 0; i < num2; i++)
	{
		cin >> p;
		m2.insert(p);
	}

	multiset<int>::iterator it1 = m1.end();
	multiset<int>::iterator it2 = m2.end();

	int max = *(--it1) + *(--it2);
	cout << max << endl;

	system("pause");
	return 0;
}