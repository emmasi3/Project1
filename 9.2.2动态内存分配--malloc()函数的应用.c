#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("请输入：");
	scanf("%d", &n);

	int* p;
	p = (int*)malloc(n * sizeof(int));

	int *d=(int*)malloc(n * sizeof(int));
	//这样写也行，等价于“*p”的那一行的写法！！！
	int* b = &n;
	printf("%p\t", b);

	int* c;
	c = &n;
	printf("%p\n", c);
	//上面给指针指明方向的“两种写法”效果一样，所以用“指针来创建长度为变量的数组时”可以在一行写，

	/*1.
	  *解读：（1）malloc()函数的作用：分配一片指定大小的空间，返回值为： void*,指针，并且这个“指针”指向了分配的空间
	  *      （2）(int*）强制转化 void* 为int* 的指针，然后赋给 p 指针
	  *      （3）于是p拥有了这片 指定“大小”、“类型”的空间，一个以 “n”为“长度”的数组由此诞生，即   p[]  
	  */
	int* a;
	int cnt = 0;
	while ( (a = malloc(1000 * 1024 * 1024)) ) {
		cnt++;
	}
	printf("最大分配内存大约是：%d000MB\n", cnt);
	free(a);
	/* 2. malloc()函数与 free()函数是必须在一起的，有malloc()就要有free()，因为：malloc()向 “系统”借内存，
	  * 如果借了不还，那么总有空间接完的一天，尤其是“大程序”3A 游戏一类的，一借就是 GB 往上，不free()释放内存，还回去
	  * 直接崩溃，没什么好说的
	   3. free()函数，返还时必须是“借”的时候的“原地址”，如：
	            int *a=(int *)malloc(n*sizeof(int));
			    int c=*(a++);
				free(a);
			这时候，a 显然地址已经变了，这时候程序崩溃，所以，必须是输入 free(原来地址指针);
	 */


	return 0;
}