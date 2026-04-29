#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>
#include <math.h>

int isprime(int x,int array[], int n);

int main()
{
	int array[2] = {[0]=0};

	int x;
	printf("请输入:\n");
	scanf("%d", &x);
	//
	//array下标
	int n = 0;
	//
	int i = 0;
	for (i = 0; i < 2; i++) {
		if (isprime(x, array,n)) {
			printf("%d是素数\n",x);
			n++;
		}
		else {
			printf("%d不是素数\n",x);
		}
		if (i != 1) {
			scanf("%d", &x);
		}
	}
	//遍历array
	for (i = 0; i < 2; i++) {
		printf("%d\t", array[i]);
	}
	return 0;
}
int isprime(int x,int array[], int n) {
	int y=1;
	//判断x
	int i=2;
	do {
		if (x % i == 0&&x!=2) {
			y = 0;
			break;
		}
		else if (x == 1) {
			y = 0;
			break;
		}
		i++;
	} while (i <= pow(x, 0.5));//判断素数时，一般方法，遍历[2，x]之间所有整数，看是否整除，一旦，x太大，那么循环次数
	//构建素数表--use数组       ，加多，程序运行效率减慢，代码质量不行，所以得想办法简化算法，
	if (y == 1) {           //这里用到了  只需要遍历到 [2,x^0.5]就行了，原理：：：：
		array[n] = x;
	}

	return y;
}/*原理：   x>y>z,而x*y=x,且x=根x*根x,所以有--y>x^0.5>z,类比对半分开，x%y==x%z==0,所以，倒着遍历 和 正序遍历结果一样
            都能找出 x为素数的依据 or x不为素数的依据，故：：只需要遍历到 pow(x,0.5)即可
 */