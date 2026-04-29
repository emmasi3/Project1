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
	ifstream ifs;
	
	ifs.open("Person.txt", ios::in | ios::binary);

	//判断
	if (ifs.is_open() == 0)
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	else
	{
		cout << "文件已打开" << endl;
	}

	//读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));  // 这一行好像是给对象 p 粘贴了一份来自 Person.txt中的属性值，
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}   这样是行不通的

	cout << "姓名：" << p.a << "  年龄：" << p.age << endl;

	ifs.close();

	system("pause");
	return 0;
}