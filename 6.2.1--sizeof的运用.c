#include <stdio.h>
int main()
{
	int a = 3;

	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(double)=%d\n", sizeof(double));
	//1. sizeof()可以输出变量所占用的内存---以“X”字节的方式

	printf("sizeof(a++)=%d\n", sizeof(a++));
	printf("a=%d",a);
	//2. sizeof()为一个“静态运算符”，它里面的a++不会执行，只会将"a++"作为-- int 类型的变量处理
	// .  也就是说在sizeof()中的“一切运算”的都是“徒劳的”！！！

	printf("sizeof(a+1.0)=%d\n", sizeof(a+1.0));
	printf("sizeof(a+1)=%d\n", sizeof(a+1));
	//3. a+1.0---为double 类型，同化了a--int类型，所以输出结果为，8
	// . a+1---为int 类型，所以结果为，4

	return 0;
}