#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	///int foot=0;
	///int inch=0;(英尺)
	///printf("请输入尺寸:");
	///scanf("%d %d",&foot,&inch);
	///int sum=0;
	///sum=(foot+inch/12)*0.3048;
	///printf("换算后的尺寸:%d（米）",sum);
	/// return 0;
	/// 如果你这样写代码，那么将会收获完全错误的数据，reason--int为整数类型的总称，则foot,inch均为整数性质的变量
	/// 计算机无法直接算，如：10/3==3.33333···,将会被将计算为3，自动舍去小数点后面的一切，此时就需要去改动一些东西来实现
	/// 我们的目的
	/// 第一如：2.1.6浮点数1，，，，，第二如下：
	int foot = 0;
	int inch = 0;
	printf("请输入：");
	scanf("%d %d", &foot, &inch);
	printf("真实尺寸：%f", (foot + inch /12.0) * 0.3048);

	return 0;

}
//这种是直接从最后的结果下手，简便至极
//但是要注意  1.%f表示浮点占位，就是输入的内容必须为小数，12.0才可以，12都不行！！！！！
//            2.foot+inch为整数类型，/12.0即为小数类型，因为整数除以小数，必会是一个小数！！！否则便会直接省略小数部分
