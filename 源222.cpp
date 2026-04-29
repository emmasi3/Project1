#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
#include <memory>

using namespace std;

void log(const string& name = "root")
{
	string m_name = name;
	cout << name << " " << m_name << endl;
}


int main()
{
	//std::vector<int*> L;
	//int p[5] = { 1,2,3,4,5 };
	//for (int i = 0; i < 5; i++)
	//{
	//	L.push_back(&p[i]);
	//	std::cout << *L[i] << std::endl;
	//}

	//printf("~~~~~~~~~~~~~~~~\n");

	//for (std::vector<int*>::iterator it = L.begin(); it != L.end(); ++it)
	//{
	//	std::cout << **it << std::endl;
	//}

	//printf("~~~~~~~~~~~~~~~\n");

	//for (auto it : L)
	//{
	//	cout << it << endl;
	//}
	//printf("~~~~~~~~~~~~~~~\n");
	//for (auto& it : L) // (int*)& 加了一个引用而已，嗯嗯，没什么新意
	//{
	//	cout << *it << endl;
	//}
	//printf("~~~~~~~~~~~~~~~\n");
	//int a = 1;
	//int ret = std::erase(L,&a); // C++20 新API，里面还是O(n),嗯嗯，简化了写法
	//for (auto& it : L)
	//{
	//	cout << *it << endl;
	//}
	//cout << "返回值为：" << ret << endl;

	//const std::string& name = "root") : m_name(name)

	const std::string& name = "root";
	cout << name << endl;

	string m_name = name;

	const char* a_name = "root";

	cout << m_name << endl;

	cout << endl;

	log();

	return 0;
}