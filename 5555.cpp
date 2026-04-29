#include <iostream>
using namespace std;
#include <string>
#include <string.h>

int main()
{
	char p[100000] = { 0 };
	char arr[100] = { 0 };
	cin >> p;
	char a=0;
	int n = 0;
	int len = strlen(p);
	int n = 0;
	//
	int ii = 0;
	//
	int k = 0;
	for (int i = 0;i<len; i++)
	{
		a = p[i];

		for (int j = i+1; j<len; j++)
		{
			if (a == p[j])
			{
				n = 1;
				arr[ii] = p[j];
				ii++;
				break;
			}
		}
		for (int k = 0; k < ii + 1; k++)
		{
			if (a == arr[k])
			{
				k = 1;
				break;
			}
		}
		if (n == 0 && k == 0)
		{
			cout << a ;
			return 0;
		}
		n = 0;
		k = 0;
		n++;
	}
	if (n == len)
	{
		cout << "没有你我可怎么活啊 ? 燕子!" << endl;
	}
	system("pause");
	return 0;
}
