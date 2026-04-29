#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	//
	bool* judge;
	judge = (bool*)malloc((n+1) * sizeof(bool));
	//
	for (int i = 2; i < n + 1; i++)
	{
		if (!judge[i])//没标记过--不进if()--是质数
		{
			continue;
		}
		cout << i << " ";
		for (int j = i * 2; j < n + 1; j += i)
		{
			//if (judge[j] == 0)
			//{
			//	continue;
			//}
		//以上部分是“欧式筛法”，额···好像是吧，也许？但是运行速度确实快了一点（在生成“诊断级别”面板看的）
			judge[j] = 0;
		}
	}
	//
	free(judge);
	system("pause");
	return 0;
}
//1. bool 类型的数组，里面默认装的是 205？反正也算是 “真” 