#include <iostream>
using namespace std;

class drink
{
public:
	//1. ÖóË®
	virtual void heatupwater() = 0;
	//2. ³åÅİ**
	virtual void brew() = 0;
	//3.µ¹Èë±­ÖĞ
	virtual void pour() = 0;
	//4.¼ÓÈë×ôÁÏ
	virtual void add() = 0;
};

class coffee :public drink
{
public:
	virtual void heatupwater()
	{
		cout << "ÖóË®" << endl;
	}
	virtual void brew()
	{
		cout << "³åÅİ¿§·È" << endl;
	}
	virtual void pour()
	{
		cout << "µ¹Èë±­ÖĞ" << endl;
	}
	virtual void add()
	{
		cout << "Ìí¼ÓÅ£ÄÌºÍÌÇ" << endl;
	}
};

class tea :public drink
{
public:
	virtual void heatupwater()
	{
		cout << "ÖóË®" << endl;
	}
	virtual void brew()
	{
		cout << "³åÅİ²èÒ¶" << endl;
	}
	virtual void pour()
	{
		cout << "µ¹Èë±­ÖĞ" << endl;
	}
	virtual void add()
	{
		cout << "Ìí¼ÓÄûÃÊ" << endl;
	}
};

void test01()
{
	drink* p = new coffee;
	cout << "³åÅİ¿§·ÈµÄ²½Öè" << endl;
	p->heatupwater();
	p->brew();
	p->pour();
	p->add();
	delete p;
}
void test02()
{
	drink* p = new tea;
	cout << "³åÅİ²èµÄ²½Öè" << endl;
	p->heatupwater();
	p->brew();
	p->pour();
	p->add();
	delete p;
}

int main()
{
	test01();
	cout << endl;
	test02();

	system("pause");
	return 0;
}