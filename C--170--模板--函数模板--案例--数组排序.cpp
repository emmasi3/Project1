#include <iostream>
using namespace std;

template<class T>
void mysort(T p[],int len)//1.“插入排序”函数模板--
{
	T* pp = NULL;
	pp = (T*)malloc(len * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		pp[i] = p[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (p[i] < pp[j])
			{
				pp[j + 1] = pp[j];
				pp[j] = p[i];
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		p[i] = pp[i];
	}
	free(pp);
}

template<typename T>
void myprintf(T p[], int len)//2.“打印”模板函数
{
	for (int i = 0; i < len; i++)
	{
		cout << p[i];
	}
	cout << endl;
}

int main()
{
	int num = 0;
	char p[] = "yghba";
	num = sizeof(p) / sizeof(char);

	mysort<char>(p,num);
	myprintf<char>(p, num);

	system("pause");
	return 0;
}