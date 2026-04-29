#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define 策划 1
#define 美术 2
#define 研发 3
//1.利用宏定义在开头指出部门的编号，就好用了，直接用汉字

class employee
{
public:
	employee()
	{

	}
	employee(string name,int money)
	{
		this->name = name;
		this->money = money;
	}

	string name;
	int money = 0;
};

void addemployee_v(vector<employee>& v)
{
	string m_name = "ABCDEFJHIJ";
	string name="员工";
	int money = 0;
	for (int i = 0; i < m_name.size(); i++)
	{
		//参数准备
		name.append(m_name,i,1);
      //2. name += m_name[i]; 这个可以，但是 name = "员工"+ m_name[i] 不行，因为：这俩不是一个类型(string,char),
	  //                             但是， += 运算符是重载后的，可以连接 string , char !!!
		  //这一行也可以写：： name.append(m_name,i,1);  
		  //翻译为：拼接 m_name 中从下标为：i 开始的 1 个字符
		money = rand() % 5001 + 8000;
		v.push_back(employee(name, money));
		//参数初始化，方便下一次使用
		name = "员工";
	}
}

void hand_out_employee(multimap<int, employee>& m,const vector<employee>& v)
{
	int job = 0;
	for (int i = 0; i < v.size(); i++)
	{
		job = rand() % 3 + 1;
		m.insert(make_pair(job, v[i]));
	}
}

void myprintf(multimap<int, employee>& m)
{
	int job1 = m.count(策划);
	int job2 = m.count(美术);
	int job3 = m.count(研发);//这里需要提前定义宏定义，也可以在前面定义，但是子啊头部位置，更显眼 ！！！

	multimap<int, employee>::iterator pos = m.begin();

	cout << "部门1--策划--员工名单：" << endl;
	for (int i = 0; i < job1; i++)
	{
		cout << pos->second.name << " 工资：" << pos->second.money << endl;
		pos++;
	}
	cout << "--------------------------" << endl;

	cout << "部门2--美术--员工名单：" << endl;
	for (int i = 0; i < job2; i++)
	{
		cout << pos->second.name << " 工资：" << pos->second.money << endl;
		pos++;
	}
	cout << "--------------------------" << endl;

	cout << "部门3--研发--员工名单：" << endl;
	for (int i = 0; i < job3; i++)
	{
		cout << pos->second.name << " 工资：" << pos->second.money << endl;
		pos++;
	}
}

void test01()
{
	//1.创建并插入10个员工

	vector<employee>v;
	addemployee_v(v);
	////测试
	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i].name << " " << v[i].money << endl;
	//}

	//2.创建 3 个部门并写入 multimap 容器“维护”

	multimap<int, employee>m;
	hand_out_employee(m, v);

	//3.分部门显示所有员工及其工资

	myprintf(m);

}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	system("pause");
	return 0;
}