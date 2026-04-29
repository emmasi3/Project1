#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int one, two, five;
	//所要凑齐的金额（整数）
	int x;
	printf("请输入：\n");
	scanf("%d", &x);
	//记录组合的金额数
	int a;
	//只需一个组合时
	int N = 0;

	for (one = 1; one < 10; one++) {
		for (two = 1; two < 10; two++) {
			for (five = 1; five < 10; five++) {
				a = one * 1 + two * 2 + five * 5;//注意 a 的单位是（角）
				if (a == x * 10) {
					printf("%d张1角+%d张2角+%d张5角=%d元\n", one, two, five, x);
					goto to;    
					//N++;        一般来说，我们在特定的条件下退出整个循环，会用到如左的语句，用if以及新的变量
					//break;      （计数变量）N 来判断特定条件下的跳出操作
				}
				a = 0;
			}
			//if (N == 1)        但是，奇人自有妙招，直接用goto语句,如:上面所示
				//break;
		}
		//if (N == 1)
			//break;
	}
to:
	printf("%d元的凑法如上所示\n", x);

	return 0;
}/*goto 语句；；；；
             1. 在需要“跳出”的位置，输入   goto **;---------------**代表的是一个位置（大概可以是任意单词，但是
			 此句结尾别忘 ; 分号）
			 2. 在需要“跳出“到””的位置，输入 **上面goto 后的内容，然后结尾（此句结尾别忘了 :  冒号！！
			 是冒号，不是分号，在上面的例子中可以看出）   
			 3. goto 语句经常用来跳出“整个”循环，这是最方便的，没有之一*/