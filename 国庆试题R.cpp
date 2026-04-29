#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>v;
    string m;
    while (cin >> m)   //如何让退出这种循环，（1）当 a 数据不为 string 类型时,只需要读入字符型就可以退出
    {                                   //（2）当 a 数据为string 类型时，你不管输入什么，好像都无济于事，所以 
                                        // ctrl+Z 然后回车，就可以退出循环，这是模拟 EOF 的，但是你不能输入 EOF 或者 ^Z
                                        // 所以，得记住
        v.push_back(m);
        m = "";
    }

    int n = v.size();

    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << v[i];
        }
        else
        {
            cout << " " << v[i];
        }
    }

    system("pause");
    return 0;
}