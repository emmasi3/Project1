#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* th(char* s,char* p1 );
int main()
{
	char s[] = "helllo";
	char* p = strchr(s,'l');
	printf("%s\n", p);
	// 1. strchr()函数会搜索“第一个”遇见的目标--'l',但是不能搜索后续的东西，并且
	//  . 返回值是--'l'所在的“地址”是一个指针类型
	//  . 打印此时的 p 指针，因为： p 本身储存的是 'l'的地址，所以字符串会打印此后所有的东西，也就是--"llo"
	//  . 可是如果想要得到第二个'l'的地址呢？
	int n = 1;
	char* p1 = 0;
	char* p2 = 0;

	int N = 0;
	printf("请输入你想要'l'的位次：\n");
	scanf("%d", &N);

	while (n < N) {
		p1 = strchr(s, 'l')+1;
		p2 = strchr(p1, 'l');
		//
		int sL = strlen(s) + 1;
		int p1L = strlen(p1) + 1;
		th(s, p1, sL, p1L);
		//
		printf("%s\n", p2);
		n++;
	}
	if (n == 1) {
		p1 = strchr(s, 'l');
		p2 = strchr(p1, 'l');
	}
	printf("%s,%p\n", p2,p2);

	return 0;
}
char* th(char* s, char* p1,int sL,int p1L) {
	printf("%c\n", *p1);
	char *p11;
	p11 = (char*)malloc(strlen(p1) + 1);
	strcpy(p11, p1);
	//
	int i;
	for (i = 0; i < sL; i++) {
		s[i] = '\0';
	}
	printf("%s\n", s);

	for (i = 0; i < 4; i++) {
		s[i] = p11[i];
	}
	printf("%s\n",p11);

	strcpy(p1, p11);
	printf("%s\n", s);

	printf("%s\t%s\n", s,p11);

	free(p11);
}