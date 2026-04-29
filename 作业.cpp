#include <iostream>
using namespace std;

int main()
{

	int p[] = { 0,1,2 };
	int* a = p;
	int pp[3];
	int* aa = pp;

	aa[1] = a[1];
	cout << &aa[1] << endl;
	cout << aa[1] << endl;

	system("pause");
	return 0;
}