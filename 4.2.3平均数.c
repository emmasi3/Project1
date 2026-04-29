#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//次数
	int n = 0;
	//总和
	int sum = 0;
	//输入
	int M;
	printf("请输入整数：\n");
	scanf("%d", &M);
	//判断刚输入是否==-1
	if (M == -1) {
		sum= -1;
		n = 1;
	}//处理了直接输入-1的行为
	else {
		while (M != -1) {
			sum += M;
			n++;
			printf("请您再次输入一个整数：\n");
			scanf("%d", &M);
		}
	}
	//计算平均数
	double avg = sum*1.0 / n;//////////这一点很重要，average不一定是整数，所以得用到double浮点数，但是俩整数相除，结果
	      ////////////依旧为整数类型，只不过会舍去小数部分，*0.1的目的就是让式子中出现浮点数，保证类型不出错！！！！！！！
	printf("所求平均数为：%lf", avg);

	return 0;
}