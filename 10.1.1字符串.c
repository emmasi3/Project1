#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//char word[] = { 'H','e','l','l','o', };
	// 
	// 1. 现在，word[]并不是一个“字符串”，只是一个“字符-数组”
	
	//char word[] = { 'H','e','l','l','o',0};
	//char word[] = { 'H','e','l','l','o','\0'};
	// 
	// . 上面这两行是“一个效果”，但是有什么区别呢？现在只知道“大小”不同。。其余不知道，但是，在我们常用的一个“字符串
	//   长度并不是'hello'--5字节
	// . 而是 6字节，因为“系统”会自动填写一个 0 或者 \0 ，
	char word[] = { 'H','e','l','l','o',0};
	int  i;
	for (i = 0; i < sizeof(word) / sizeof(char); i++) {
		if (i == sizeof(word) / sizeof(char) - 1) {
			printf("%c\n", word[i]);
	// 2. char 类型的数据，输出的话，用" %c "
		}
		else {
			printf("%c", word[i]);
		}
	}
	// 3. 字符串--定义：一串“以 0，\0 结尾”的 字符，用 ""括起来的部分。--往往这个 0 会被省略，或者遗忘
	char* str = "Hello";
	printf("%p\n", str);
	printf("%c\n",*str);
	char* p = str + sizeof("Hello") / sizeof(char)-1;
	// ()上面这一行是为了--保存最会一个单位的“地址”。当然，也可以不这样遍历这个“字符数组”
	for (str; str <=p; str++) {
		if (str == p ) {
			printf("%c\n", *str);
		}
		else {
			printf("%c", *str);
		}
	}
	printf("%p\n", str);
	str = str - sizeof("Hello") / sizeof(char) - 1;
	printf("%p\n", str);
	// TMD 也可以这样遍历一个“字符串--数组”
	for (i = 0; i < sizeof("Hello") / sizeof(char); i++) {
		if (i== sizeof("Hello") / sizeof(char)-1) {
			printf("%c\n", str[i]);
		}
		else {
			printf("%c", str[i]);
		}
	}

	char* point = "Hello";
	char array[] = "Hello";
	char line[10] = "Hello";
	printf("%c\n", line[4]);
	printf("%c\n", line[5]);
	// 4. "Hello"在line[10]，中占据了 “6个字节”，因为字符串写入数组时，会默认最后跟个 0，但这不是整数0，
	//  . 最后一行代码的结果 什么都没有，在“终端”上
	return 0;
}