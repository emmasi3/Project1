#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 5;
	int i = 1;
	int fact = 1;
	for (i = 1; i <= n;) {//1. 这里标准的是：for(i=1;i<=n;i++),其中：  i=1为初始条件
		fact *= i;       //                 i<=n--为执行体，，，， i++为每轮（第2轮及其以后）循环要做的事，但是第一轮循环中，输入进去的
		printf("%d\n", i); //i=1按照初始值进行，不执行i++，而实在第二次及以后，进行完for那一行后，i++才执行，！！
		i++;             //这是比较难理解的一处！！仅仅是我个人的理解！
	}
	printf("%d\n", fact);

	return 0;
}