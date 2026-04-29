#include <bits/stdc++.h>
using namespace std;

int TOT = 0;
int cheat = 0;
int a = 0, b = 0, c = 0;

void add_A()
{
	a++;
	TOT++;
}

void add_B()
{
	b++;
	TOT++;
}

void add_C()
{
	c++;
	TOT++;
}

int main()
{
	int choice = 0;
	cin >> choice;
	while (choice != -1)
	{
		switch (choice)
		{
		case 1:
			add_A();
			break;
		case 2:
			add_B();
			break;
		case 3:
			add_C();
			break;
		default:
			cheat++;
			break;
		}
		cin >> choice;
	}

	cout << "A=" << a << endl;
	cout << "B=" << b << endl;
	cout << "C=" << c << endl;
	cout << "Tot=" << TOT << endl;

	//1.放进map <ticket,Person>
	multimap<int, string>m;
	m.insert(make_pair(a, "A-yes"));
	m.insert(make_pair(b, "B-yes"));
	m.insert(make_pair(c, "C-yes"));

	//2.看最大是否超过半数？
	multimap<int, string>::iterator pos = m.end();
	pos--;
	if ((*pos).first > (cheat+TOT)/2)
	{
		cout << (*pos).second << endl;
	}
	else
	{
		cout << "all-No" << endl;
	}

	system("pause");
	return 0;
}