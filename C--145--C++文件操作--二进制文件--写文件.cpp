#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Person
{
public:
	char a[100];
	int age;
};

int main()
{
	//1.头文件

	//2.创建对象
	// ifstream ifs; 以下两种方式都可以
	fstream ifs("Person.txt", ios::out | ios::binary);

	//3.写内容
	Person p = { "张三",18 };
	ifs.write((const char*)&p, sizeof(p));

	string buf;
	getline(ifs, buf);
	cout << buf << endl;

	//4.关闭文件
	ifs.close();

	system("pause");
	return 0;
}