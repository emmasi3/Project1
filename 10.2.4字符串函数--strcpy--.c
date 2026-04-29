#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* copy(char p0[],const char p4[]);
int main()
{
	char p4[] = "Hello,world";
	char p2[] = "Hello";
	char* p1 = (char*)malloc(strlen(p2)+1);
	printf("%s\n", strcpy(p1, p2));
	// 1. 此函数将 p2的内容“复制”给p1，这时候p1[]是空的，但是当p1[]有东西的时候呢？这个暂时不知道
	char p3[] = "Hello,world";
	printf("%s\n", strcpy(p3, p2));
	// 2. 现在来自己写一个strcpy()函数的类似函数--copy()
	char* p0 = (char*)malloc(strlen(p4)+1);
	copy(p0, p4);
	printf("%s\n", p0);
	printf("%s\n", copy(p0, p4));
	//  . 因为：不能直接修改数组，所以咱们用指针的方式，直接修改每个单元的值，从而跨“函数/块”实现“复制”的目的

	free(p1);
	free(p0);
	return 0;
}
char* copy(char p0[], const char p4[]){
	while(p0[strlen(p4)]!='\0') {
		*p0 = *p4;
		p0++;
		p4++;
	// 3. 注意：关于“数组”与“指针”还是了解的不够“透彻”，定义了一个指针 p0,进而动态分配出了一个 p0[]数组
	//  . 想要给 p0所“指”的空间里的单位“赋值”, p0本身储存地址，无论是被看作是指针还是数组，而 * 则是访问后面“地址
	//  . 所在单位的“值”，这一点永远不会变。。但是人可以基于不同的角度，理解它，应用它
	//  . 

	}
	return &p0[0];
}
    // 4. 对于一个函数copy而言，可以定义函数类型为“指针”，即 int* 或者char*类型
    //  . 注意：“ 地址 ”的数据类型主要是“ 指针 ”