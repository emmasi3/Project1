#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	void setname(string m_name) {
		name = m_name;
	}
	void getname() {
		cout << "姓名：" << name<<endl;
	}

	void getage() {
		cout << "年龄：" << age << endl;
	}
	void steido(string m_ido) {
		ido = m_ido;
	}

private:
	string name;

	int age;

	string ido;
};
//1. 可以将成员属性先都设置为 “私有”，这样在类外就不能够访问，只能通过“类内”的访问直接打印到“终端”|| 调用，
// 并且，可以自己就设置 成员属性的 “读，写” 权限
int main()
{
	Person p1;
	p1.setname("张三");

	system("pasue");
	return 0;
}