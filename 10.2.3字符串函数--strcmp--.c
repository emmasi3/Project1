#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void cmp(const char p1[],const char p2[], int len, int len1, int len2);
void cmp2(const char p1[], const char p2[]);

int main()
{
	const char p1[] = "abc";
	const char p2[] = "abc ";
	printf("%s\n",p1);
	printf("%d\n", strcmp(p1, p2));
	printf("%d\n", '\0' - ' ');
	int c = strcmp(p1, p2);

	if (c > 0) {
		printf("p1>>p2\n\n");
	}
	else if (c == 0) {
		printf("p1===p2\n\n");
		// 这里没有 p1==p2 ,因为，p1 与 p2 两个数组的“地址”不可能相等，所以程序中也就不要出现相应的语句
	}
	else if (c < 0) {
		printf("p1<<p2\n\n");
	}
	// 1. 现在我们来写自己的 strcmp() 函数
	int len1 = sizeof(p1) / sizeof(char);
	int len2 = sizeof(p2) / sizeof(char);
	int len;
	//  . len 为长度最小的
	if (len1 >= len2) {
		len = len2;
	}
	else {
		len = len1;
	}
	cmp(p1,p2,len,len1,len2);
	// 2. 函数cmp2()更加简简洁！！！用的是while()循环，而我自己写的 for()循环又臭又长，
	// 但是总归是运行没问题，思路也没问题。  思路多多，走路不怕||
	cmp2(p1, p2);
	return 0;
}
void cmp(const char p1[],const char p2[], int len,int len1,int len2) {
	int i;
	int t;
	int n=0;
	for (i = 0; i < len; i++) {
		t = p1[i] - p2[i];
		if (t>0) {
			printf("p1>>p2\n");
			break;
		}
		else if (t < 0) {
			printf("p1<<p2\n");
			break;
		}
		else if(t == 0) {
			n++;
		}
	}
	if (n == 4 && len1 > len2) {
		printf("p1>>p2\n");
	}
	else if (n == 4 && len1 == len2) {
		printf("p1===p2\n");
	}
	else if (n == 4 && len1 < len2) {
		printf("p1<<p2\n");
	}

}
void cmp2(const char p1[], const char p2[]) {
	while (*p1==*p2 && *p1!='\0' && p2!='\0') {
		p1++;
		p2++;
	}
	int n = *p1 - *p2;
	if (n > 0) {
		printf("p1>>p2");
	}
	else if (n == 0) {
		printf("p1===p2");
	}
	else if (n < 0) {
		printf("p1<<p2");
	}
}