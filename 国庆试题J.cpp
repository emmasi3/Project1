#include <bits/stdc++.h>
using namespace std;

void add_v(vector<int>& v,int n)
{
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		v.push_back(p);
	}
}

int num = 0;

void myprintf(int v)
{
	num++;
	if (num == 1)
	{
		cout << v;
	}
	else
	{
		cout << " " << v;
	}
}

int main()
{
	int n;
	while (cin>>n)//5.!!!这个循环体，如果成功读入并且成功赋值给n，(cin>>n)整体为true,否则(cin>>n)整体为false
	{
		//1.装进 v 
		vector<int>v;
		add_v(v, n);

		//2.找m（第一个出现）
		int m;
		cin >> m;

		vector<int>::iterator pos = find(v.begin(), v.end(), m);
		//3.分情况，找到了，输出。没找到，原数组

		if (pos != v.end())
		{
			v.erase(pos);
		}
		if (v.size() != 0)
		{
			for_each(v.begin(), v.end(), myprintf);
		}
		cout << endl;
		num = 0;
	}


	system("pause");
	return 0;
}