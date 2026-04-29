#include <iostream>
using namespace std;

int main()
{
	char arr[] = "hello";
	//ÄæÖÃ
	char p[6];
	for (int i = 0; i < 5; i++) {
		p[i] = arr[4 - i];
	}
	for (int i = 0; i < 5; i++) {
		arr[i] = p[i];
	}
	cout << "arr[]=";
	for (int i = 0; i < 5; i++) {
		cout << arr[i];
	}
	cout << "\n";

	system("pause");
	return 0;
}