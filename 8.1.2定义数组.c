#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <corecrt_malloc.h>


int main()
{
	int *number;
	//数组长度
	int n;
	printf("请输入数组长度:\n");
	scanf("%d", &n);
	//定义数组
	number = (int *)malloc(n * sizeof(int));

	//读入数据
	int x;
	printf("请输入：\n");
	scanf("%d", &x);
	//总和
	int sum=0;
	//实际个数（输入的）
	int rn = 1;
	//数组单位数
	int i = 0;
	while (rn<=n) {
		number[i] = x;
		i++;
		sum += x;
		rn++;
		printf("请再次输入:\n");
		scanf("%d", &x);
	}
	double average = sum * 1.0 / n;
	printf("平均数为：%f\n", average);
	printf("数组中容量为：\n", i);

	for (i = 0; i <= n; i++) {
		if (number[i] > average) {
			printf("%d\t", number[i]);
		}
	}
	free(number);//这就相当于清空number中的内容！！！

	if (number[0] == 1) {
		printf("free后没看出来效果\n");
	}
	else {
		printf("清除了number中所有值\n");
	}
	
	return 0;
}
/*总结：1. 一般--  int number[10];
        表示定义了一个 所有元素应该为int 类型的，容量为10的数组，也可以为
		double number[0],但是此时，数组长度为0，没有任何意义，但是“编译”能“通过”
		2. 在dev c++软件中，如果一开始不确定“数组的容量到底应该多大？”，可以直接  int number[n];用变量n来做
		容量的参数，但是n“必须”要在这串代码之前有“明确的常数值”
		但是 vs code 不支持最新的c99协议，所以这条方法不能用
		3. 上述代码所示的方法：用“指针”进行动态内存的分配，没了解，之后再看
		4. 不管是动态的，还是静态的 容量参数--在“定义数组代码完成之后”，下面的任何代码都“不能”对数组的容量做修改
		例如：一个马克杯，（1）厂家自己设定，尺寸常数--[10]明确
		                  （2）用户提明确的要求，--[n]变量以及“指针动态内存分配”
		5. 如果要使用指针的方法，在开头需要引入 数据库--          <corecrt_malloc.h>    
		否则，不能够使用malloc()函数----------这也是最容易忽略的一点，就如同第一次使用scanf()函数时！！！
		*/