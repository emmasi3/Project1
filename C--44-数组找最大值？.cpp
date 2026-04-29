#include <iostream>
using namespace std;

int main()
{
	int arr[5] = { 200,350,896,1562,523 };
	int max = 0;

	for (int i = 0; i < 5; i++) {
		if ( arr[i]>max ) {
			max = arr[i];
		}
	}
	cout << "最重的猪体重为：" << max <<"kg"<< endl;

	system("pause");
	return 0;
}