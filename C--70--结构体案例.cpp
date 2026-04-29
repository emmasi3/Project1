#include <iostream>
using namespace std;
#include <string>

struct hero {
	string name;
	int age;
};

int main()
{
	hero a = { "刘备",23 };
	hero b = { "关羽",22 };
	hero c = { "张飞",20 };
	hero d = { "赵云",21 };
	hero e = { "貂蝉",19 };
	//1. 按照年龄的升序，输出对应的名字排序
	int arr[5] = { a.age,b.age,c.age,d.age,e.age };
	string pL[5];

	int min = 10000;
	int n = sizeof(arr) / sizeof(arr[0]) - 1;
	int p[5];
	for (int j = 0; j < n + 1; j++) {
		for (int i = 0; i < n + 1; i++) {
			if (j == 0) {
				if (min > arr[i]) {
					min = arr[i];
				}
			}
			else {
				if (min > arr[i] && arr[i] > p[j - 1]) {
					min = arr[i];
				}
			}
		}
		p[j] = min;
		//2. 打印对应的名字，按升序
		switch (min) {
		case 23:
			cout << "刘备" << endl << endl;
			pL[j] = a.name;
			break;
		case 22:
			cout << "关羽" << endl;
			pL[j] = b.name;
			break;
		case 20:
			cout << "张飞" << endl;
			pL[j] = c.name;
			break;
		case 21:
			cout << "赵云" << endl;
			pL[j] = d.name;
			break;
		case 19:
			cout << "貂蝉" << endl;
			pL[j] = e.name;
			break;
		}
		min = 10000;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << pL[i] << endl;
	}
	system("pause");
	return 0;
}