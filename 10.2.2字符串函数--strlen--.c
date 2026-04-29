#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int length(char array[]);
int main()
{
	const char array[] = "Hello";
	printf("array[]储存“字符串”的长度为：%d\n", strlen(array));
	printf("array[]的“内存”长度位：%d\n", sizeof(array));
	// 1. 在这里“长度”不一样，因为有 \0 的存在，也要占据空间，而 strlen()函数 直接输出“字符串”字符的长度
	// 
	// 2. 那如何不利用 strlen()函数输出其长度呢？（用自定义函数）
	int n= length(array);
	printf("array[]储存“字符串”的长度为：%d\n", n);
	//  . 现在利用函数便可以达到和 strlen()同样的效果，但是这里利用了一个非常重要的“等量关系”-- 
	//  . array[5]=NULL; -- 因为是“字符串”，所以必须是以“0或\0结尾”而 刚好就等于 NULL--什么都没有来表示！！！
	// 
	// 3.同时也发现一个问题，函数length()的返回值 n ，并没有改变主函数main()中 n 的值，而是 返回到“调用处”--
	//  .length(array)==n==5;
	// ;;!!!所以以后要注意，-- 不同“块”内，所属变量的值不会被轻易改变，唯一的方法是，“指针”这也就是开头
	//  . const char array[] 的原因，因为不想让其他程序改变array[]里面的东西，因为--“数组=指针”是“约等于”
	return 0;
}
int length(char array[]) {
	int i;
	int n = 0;
	for (i = 0; array[i] != '\0'/*这是最最重要的一步*/; i++) {

		n++;
	}

	return n;
}