#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int x;
	printf("请输入：\n");
	scanf("%d", &x);
	//替换
	int y = x;
	//位数
	int n = 0;
    //处理
	while (y!=0) {
		y /= 10;
		n++;
	}
	printf("%d的位数n=%d\n",x,n);
	//给“y”恢复值
	y = x;
	//次数
	int i = n;
	//记录 每位 的值
	int a;
	//eeee~~~
	printf("%d可以被拆为： ", x);

	while (i>0) {
		int h = pow(10, i - 1);//思路：//1.先利用循环，确定x的位数n
		a = y / h;                     //2.计算每一位上的数值：：第1次，利用int 的性质，取最高位为个位，进而得到值
		y = y % h;                     //3.第2.3.4.····次,每次都得到“去掉最高位后的 值”，方法：
		i--;                           //给它取余（%），不断舍去最高位，留下“其余位”****常用
		printf("%d ", a);              //4.做后续处理···
	}                                  //5.！！ pow(,)幂函数，本身为double类型，用作整数int 取余（%）时，
	return 0;                          //要int pow(,)=变量才可以，否则只能用小数类型取余了
}