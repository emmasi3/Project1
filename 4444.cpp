#include <iostream>
using namespace std;

int main()
{
    int N;//天数
    cin >> N;
    int NN = N;
    int n = 0;//增加次数
    int num = 0;//饼数
    int t;
    for (int i = 1; N > 0; i++)
    {
        N -= i;
        n++;
    }
    if (N == 0)
    {
        for (n; n > 0; n--)
        {
            num += n * n;
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            num += i * i;
        }
        t = (n - 1) * n / 2;
        num = num + (NN - t) * n;
    }
    cout << num;

    system("pause");
    return 0;
}