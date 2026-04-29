#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < sizeof(s); i++)
    {
        if (i == 2)
            cout << s[i] - '0' + 1;
        else 
            cout << s[i];
    }
    return 0;
}