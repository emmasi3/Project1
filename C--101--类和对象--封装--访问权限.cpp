#include <iostream>
using namespace std;
#include <string>

class Person
{
	//1. 公共权限
public:
	string name;
	//2. 保护权限
protected:
	string Car;
	//3. 私有权限
private:
	string Password;
};

int main()
{
	Person p1;
	p1.name = "张三";
  //p1.Car = "奔驰";
  //p1.Password = "123456789";

	//这两行代码都是不合法的，因为 2  3   都只能在“类”内访问，在类外不能访问！！！
	system("pause");
	return 0;
}