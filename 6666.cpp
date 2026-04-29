#include <iostream>
using namespace std;
#include <string>
#include <string.h>

class num
{
public:
	void get()
	{
		cout << this->name << ":" << this->cishu << "次 ";
	}
	num()
	{

	}
	num(char name, int cishu)
	{
		this->name = name;
		this->cishu = cishu;
	}
	char name;
	int cishu;
};

int q = 0;
num pp[24];
// 最后一步，冒泡排肾虚
num ppp[24];

void f1()
{
	num min('a', 0);
	for (int j = 0; j < q; j++)
	{
		for (int i = 0; i < q; i++)
		{
			if ((int)min.name > (int)pp[i].name && j == 0)
			{
				min = pp[i];
			}
			else if ((int)min.name > (int)pp[i].name && (int)pp[i].name > (int)ppp[j - 1].name)
			{
				min = pp[i];
			}
		}
		ppp[j] = min;
		min = num('a', 0);
	}
}

void f2()
{
	for (int i = 0; i < q; i++)
	{
		if (i == q)
		{
			cout << ppp[q].name << ":" << ppp[q].cishu << "次";
		}
		else if (q != 0)
		{
			ppp[i].get();
		}
	}
}

int main()
{
	char arr[24] = {0};
	int a = 0;
	int y = 0;
	//
	char p[10000] = { 0 };
	cin >> p;
	int len = strlen(p);
	int n = 0;
	//1.遍历整个字符串
	for (int i = 0;i<len; i++)
	{
		if ((int)p[i] >= 65 && (int)p[i] <= 90)//判断是否为大写字母
		{

		}
		else
		{
			continue;
		}
		//判断有无和前者重复
		for (int k = 0; k < strlen(arr); k++)
		{
			if (p[i] == arr[k])
			{
				y = 1;
				break;
			}
		}
		if (y == 1)
		{
			y = 0;
			continue;
		}
		//
		arr[a] = p[i];
		a++;
		//2.加次数
		for (int j = 0; j < len; j++)
		{
			if (p[i] == p[j])
			{
				n++;//次数
			}
		}
		pp[q] = num(p[i], n );
		q++;
		n = 0;
	}

	//特殊情况
	if (arr[0] == 0)
	{
		cout << "26个大写字母都没出现过" << endl;
	}
	f1();
	f2();

	system("pause");
	return 0;
}