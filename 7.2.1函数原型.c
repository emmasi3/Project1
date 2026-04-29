#include <stdio.h>

void sum(int a, int b);//声明
//
int main()
{
	sum(10, 20);
	sum(20, 30);
	sum(35, 45);

	return 0;
}
//
void sum(int a, int b) {//定义
	int i;
	int count=0;
	for (i = a; i <= b; i++) {
		count += i;
	}
	printf("从%d到%d的所有数的和为%d\n", a, b, count);
}
/*总结：1. 现在，流行的时将函数“类型”及“参数”在主函数main()前面发出“声明”而非“定义”--in order to
         让“编译器”顺利运行，否则，会报错
		 2. 函数声明后面得有  --；--分号结尾，否则也报错
		 3. sum(int,int)--仅仅用于函数“声明部分”不用输入具体的变量名称也可以，reason==
		 只是告诉编译器，sum()函数有两个要输入的变量的“类型”，而且编译器也“不会”检查--声明和定义--变量名称是否一致
		 即使；；；；sum(int,int b);
		 
		        void sum(int b,int a){
		 它只会精确的将“输入量”给“位置”、“顺序”---“一致”--的变量 }*/