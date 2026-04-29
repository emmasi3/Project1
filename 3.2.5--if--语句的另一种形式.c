#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int grade = 0;
	printf("请输入你的成绩：\n");
	scanf("%d", &grade);

	if (grade >= 60)
		printf("恭喜你，合格！");
	else
		printf("很遗憾，你需要重新来过··");////当此处没有 {} 符号时，if,else依旧可以运行，但是只能添加 一句 执行内容！

	return 0;
}