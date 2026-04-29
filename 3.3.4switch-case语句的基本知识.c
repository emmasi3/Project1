#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int type;
	printf("请输入type的值：\n");
	scanf("%d", &type);

	switch (type) {
	case 1:
		printf("hello world\n");
		break;
	case 2:
		printf("hello python world\n");
		break;
	case 3:
		printf("我是你大爷\n");
		break;
	default:
		printf("孩子无敌了\n");
		break;
	}

	return 0;
}
/*
总结，1.  所谓的switch-case语句，与if-else语句最大的区别就是：当上面的type==3时，if会一行接着一行地执行，直到找到
            符合条件的一句
			而switch则会直接去执行对应的case 3而不去执行case 1 , case2,
		2.  一般的if-else语句，在执行完了一个条件之后，也就是找到type==3这个条件以及下方所属的执行语句之后，仅仅会
		    执行这一小部分，而不会去执行default以及下面的东西，，，，但是switch-case则不是这样的，如果没有break约束
			那么，直接会从开始的case 3执行完下面的所有，包括可能会出现的case 4,,case5
		3.  default这一行代码，在switch-case中的含义：：：如果type的输入值没有在上面的任何一个 case 中出现，那么就会直接
		    执行default及其下面的所有直到遇到  break 语句，才会退出整个switch-case语句
		4.  它的一般形式：：：：
		    switch(控制表达式){
			case 常量:
			    ···;break;
			case 常量：
			    ···;break;
			······
			default：
			    ···;break;
			}
			
			
			
		5.  这也是最重要的一点：：：switch(表达式),的内容，必须是 整型(如：int) 或者枚举类型 类型的，double都不行！！！
		
		6、case 下的代码块，如果有关于变量的定义，那么就必须加 {}，将变量的初始化放在这个作用域中
			，因为 switch-case 语句的执行选择，类似于 goto 类型，假设在 case 1 中，
			有 int a = 0; 
			那么执行时，有时候不会执行这个情况，那么这个变量就跳过了定义，这在 C++ 中，是不允许的
			自己去搜吧，我也不知道

*/