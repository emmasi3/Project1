#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int acm;
	printf("请输入尺寸:(cm)\n");
	scanf("%d", &acm);

	double foot;
	double inch;
	double am;

	am = acm * 0.01;
	
	inch = am / (0.3048 * (12 + 1.0 / 12));///!!!!!这里注意了。如果你写成1/12，那么就会出现1/12=0,因为这一步
	                       ///电脑在处理1/12是整个算式都是整数的，他会默认为1/12的结果为 整数 类型，所以要加1.0或者12.0都可以

	
	foot = inch * 12;

	int sum = foot*12 + inch; //换算为英寸

	int turefoot = sum / 12;
	int tureinch = sum % 12; //寸这边显示的是7寸，但实际是6寸，是计算机保留结果的问题么？还是应该尽量简化计算？

	printf("换算后为：%d尺%d寸\n", turefoot, tureinch);
	
	return 0;
}