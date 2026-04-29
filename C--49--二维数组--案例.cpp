#include <iostream>
using namespace std;

int main()
{
	int arr[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
	int score = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			score += arr[i][j];
		}
		switch (i) {
		case 0:
			cout << "张三总成绩为：" << score << endl;
			break;
		case 1:
			cout << "李四总成绩为：" << score << endl;
			break;
		case 2:
			cout << "王五总成绩为：" << score << endl;
			break;
		}
		score = 0;
	}

	system("pause");
	return 0;
}