#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int j = 0;
	int k = 0;
	int sum = 0;
	//
	do
	{
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {

				sum = i * 100 + j * 10 + k;
		
				if (i * i * i + j * j * j + k * k * k == sum) {
					cout << sum << "\t";
				}
			}
		}
		i++;
	} while (sum < 1000&&i<10);

	system("pause");
	return 0;
}