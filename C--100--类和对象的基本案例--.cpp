#include <iostream>
using namespace std;
#include <string>

class Student {
	
public:

	string name;
	string xh;

	void Print() {
		cout <<"姓名：" << name << "  学号：" << xh << endl;
	}
};

int main()
{
	Student s1{ "张三","01" };
	Student s2{ "李四","02" };
	s1.Print();
	s2.Print();

	system("pause");
	return 0;
}