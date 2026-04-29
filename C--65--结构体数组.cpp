#include <iostream>
using namespace std;
#include <string>

//1. 定义结构体
struct Student {
	string name;
	int age;
	int score;
};

int main()
{//2. 定义“结构体”数组；
	Student s1 = { "赵六",21,60 };
	Student arr[3] = {
		s1,s1,s1
	};
// 2.... 也可以
	Student p[3] = {
		{"张三",18,100},
		{"李四",19,99},
		{"王五",20,98}
	};
// . Student -》相当于 数组类型，就这样理解好记	,剩下的和普通的数组，没有声明区别，除了可以用 . 号访问每一个属性

//3. 遍历输出
	for (int i = 0; i < 3; i++) {
		cout << arr[i].name <<" "<< arr[i].age <<" "<< arr[i].score << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << p[i].name << " " << p[i].age << " " << p[i].score << endl;
	}

	system("pause");
	return 0;
}