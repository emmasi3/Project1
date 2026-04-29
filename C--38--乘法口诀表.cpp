#include  <iostream>
using namespace std;

int main()
{
	int n = 1;
	int i = 1;
	int j = 1;
	int k = j * i;
	while ( n < 10 ) {
		for (i = 1; i < 10; i++) {
			for (j = 1; j < n + 1; j++) {
				k = j * i;
				cout << j << "*" << i << "=" << k<<" ";
				if (j == 2 && i == 3) {
					cout << " ";
				}
				if (j == 2 && i == 4) {
					cout << " ";
				}
			}
			cout << endl;
			n++;
		}
	}

	system("pause");
	return 0;
}