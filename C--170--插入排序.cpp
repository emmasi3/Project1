#include <iostream>
using namespace std;

int main()
{
	int p[10] = { 5,6,8,7,4,15,53,64,99 };
	int N = 10;
	int pp[10] = { 0 };
	for (int i = 0; i < N; i++)//1.第一层循环--保证所有的 p[i] 被遍历
	{
		pp[i] = p[i];//2.放在这里，保证每一轮循环都可以给 pp[] 里面新增数据 --- 仅仅在 if()语句下添加给pp[] 数据是不够的
		for (int j = i - 1; j >= 0; j--)//原因：第一层的循环次数是有限的，而if()条件语句不是每一次都执行的，所以绝对
		{                               // 有的数据不能被写进 pp[] 中去，所以结果绝对不正确
			if (p[i] < pp[j])//3.第二层循环作用：从 pp[] 的最高位起开始遍历，从上往下，如若下一次需要写入的 p[i] 符合条件
			{                // .则下面这两行代码会直接“交换数据”，当然交换部分不止这一种写法，
				pp[j + 1] = pp[j];//另一种：如果不想在if()中 用 到原数组 p[] ，那么就必须如 swap() 那样，先保存被覆盖的
				pp[j] = p[i];    //pp[j+1],再交还给pp[j]
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << pp[i] << "\t";
	}
	cout << endl << endl;
	//下面是“降序”-- 插入排序
	int ppp[10] = { 0 };
	for (int i = 0; i < N; i++)
	{
		ppp[i] = p[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (p[i] > ppp[j])
			{
				ppp[j + 1] = ppp[j];
				ppp[j] = p[i];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << ppp[i] << "\t";
	}

	system("pause");
	return 0;
}