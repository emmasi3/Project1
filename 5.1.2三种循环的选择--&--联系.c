#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int n = 5;
	int sum = 0;

	for (i = 0; i < n; i++) {  //如此为一个，标准的for循环，它可以被改写为完全等价 == 的while循环
		sum += i;
	}

	/*i = 0;
	  while (i < n) {            i=0为初始条件，在while循环之前...
		  sum += i;              i<n为执行体，在while()内...
		  i++;                   sum+=i为循环内容，在while内部...
	  }                          i++为变量的改变，在while内，但是却在“最后”执行...*/




	printf("%d\n", sum);

	return 0;
}
/* 总结：1.  如果循环有固定次数----for循环（不理解）
         2.  如果必须执行一次***   do-while 循环
		 3.  其他的情况--- while（）循环
		 */