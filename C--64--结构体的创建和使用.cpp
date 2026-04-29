#include <iostream>
using namespace std;
#include <string>

//
struct Student {
	string name;
	int age;
	int score;
}s3;
//
int main()
{
	//1.1 创建学生具体人物时的方式1
	struct Student s1; //直接先创建s1,前面的 struct Student 可以看作“类型”
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;
	                 //！！！！！ “ . ” 号可以用来访问结构体中Student 的定义**********************
	//2.2 第二种方式
	Student s2 = { "李四",19,80};
	// . 直接按顺序写，这样比较方便，但是实在可以清楚结构体有多少个属性的情况下

	//3.3 第三种方式，在创建结构体后面直接创建 具体事物
	// . 比如 创建 Student 时候的 s3,类似于第一种方式，这个不常用，但是别人的代码里面可能有，所以要知道

	system("pause");
	return 0;
}