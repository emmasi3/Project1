#include <bits/stdc++.h>
using namespace std;

void add_v(vector<int>& v,int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
}

void add_s(set<int>& s, const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		s.insert(v[i]);
	}
}

void add_m(multimap<int, int>& m, const set<int>& s, const vector<int>& v)
{
	int num = 0;
	for (set<int>::const_iterator it=s.begin();it!=s.end();it++)
	{
		num = count(v.begin(), v.end(), *it);
		m.insert(make_pair(num, *it));
	}
}

void myprintf(int a)
{
	cout << a << " ";
}

int main()
{
	int n;
	cin >> n;
	//1.传进去
	vector<int>v;
	add_v(v, n);

	//2.得到种类
	set<int>s;
	add_s(s, v);

	//for_each(s.begin(), s.end(), myprintf);
	//cout << endl;

	//3.按次数排序，找最大
	multimap<int, int>m;
	add_m(m, s, v);

	//4.打印 m 的最后一个对组的 second -- 目标
	multimap<int, int>::iterator it = m.end();
	it--;
	cout << (*it).second;

	system("pause");
	return 0;
}