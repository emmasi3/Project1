#include <iostream>

struct LogIniter
{
	LogIniter()
	{
		std::cout << "Log模块初始化开始了！" << std::endl;
	}
};

static LogIniter __log_int;

/*
* 1、一个有链接属性，一个没有链接属性
*	加 static 不是为了改变内存，而是为了让全局变量只属于当前 .cpp 文件，避免符号污染和链接冲突；
*	不加 static 则是全局变量，全局可见，可被其他文件访问。、
* 
* 2、这里将扩大讨论的范围！！！！！
* 
* 3、问：既然 static 修饰的全局变量不能被外部文件访问，那么是不是说所有被 static 修饰的东西（函数，命名空间【本质还是全局】，类···）
*	（1）static + 函数（普通），不能被外部访问
*	（2）static + 全局变量，不能
*	（3）static + 类成员函数，能，但是要通过类
*	（4）static + 类成员变量，能，但是要通过类
*	（5）static + 类成员内部局部静态变量，能，但是要通过类的该函数才可以
* 
*/

int main()
{


	return 0;
}