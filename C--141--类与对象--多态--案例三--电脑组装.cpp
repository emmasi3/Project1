#include <iostream>
using namespace std;
#include <string>

class CPU
{
public:
	virtual void calculate() = 0;
};

class GPU
{
public:
	virtual void pictureworkout() = 0;
};

class DDR
{
public:
	virtual void save() = 0;
};

class computer :public DDR
{
public:
	virtual void calculate()
	{
		cout <<this->C_name<< "正在计算···" << endl;
	}
	virtual void pictureworkout()
	{
		cout <<this->G_name<< "正在处理图形···" << endl;
	}
	virtual void save()
	{
		cout <<this->D_name<< "正在储存···" << endl;
	}

	computer(string n1,string n2,string n3)
	{
		this->C_name = n1;
		this->G_name = n2;
		this->D_name = n3;
	}
	string C_name;
	string G_name;
	string D_name;

};

void test01()
{
	cout << "请依次输入电脑配置：CPU，GPU，DDR" << endl;
	string a;
	cin >> a;
	string b;
	cin >> b;
	string c;
	cin >> c;

	DDR* com = new computer(a, b, c);
	com->save();
	cout << com << endl;
	delete com;             //1. 当computer 多继承的时候，这一行将直接报错，不再执行
	com = NULL;
	cout << "5555" << endl;
	
}

int main()
{
	test01();

	system("pause");
	return 0;
}