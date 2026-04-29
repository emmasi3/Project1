#include <iostream>
using namespace std;
#include <string>

//1. 创建学生
struct student {
	string name;
	int age;
	int score;
};
struct teacher {
	string name;
	int age;
	student s1;
};

int main()
{
	//创建具体学生
	student s1 = { "张三",18,100 };
	//创建具体老师
	teacher t1 = { "老王",34,s1 };

	cout <<t1.name <<"的学生：" <<s1.name<<" 年龄"<<s1.age <<" 成绩"<<s1.score << endl;
	// 老王的学生：张三····，
	// 这就是“嵌套”的作用情形，表示从属关系，我感觉它也可以用作循环嵌套语句中，做一些工作

	system("pause");
	return 0;
}