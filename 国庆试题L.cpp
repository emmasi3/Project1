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

int main()
{
	int n;
	while (cin >> n)
	{
		//1.放进V
		vector<int>v;
		add_v(v, n);

		int m;
		cin >> m;
		//2.找到m所在位置（首地址）
		vector<int>::iterator pos = find(v.begin(), v.end(), m);

		//3.判断有无，并记录位置
		if (pos == v.end())
		{
			cout << "No" << endl;
		}
		else
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == *pos)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}

	system("pause");
	return 0;
}