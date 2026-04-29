#include <bits/stdc++.h>
using namespace std;

int N = 0;//最大数位数
int M = 0;//最数小位数
void find_max(string m, string n)
{
    if (m.size() > n.size())
    {
        N = m.size();
    }
    else
    {
        N = n.size();
    }
}

void find_min(string m, string n)
{
    if (m.size() > n.size())
    {
        M = n.size();
    }
    else
    {
        M = m.size();
    }
}

int add_mm_nn(int* mm, int* nn, string m, string n)
{
    int cha = m.size() - n.size();
    if (cha < 0)
    {
        cha = (-1) * cha;
        for (int i = 0; i < cha; i++)
        {
            mm[i] = 0;
        }
        for (int i = cha; i < N; i++)
        {
            mm[i] = m[i - cha]-'0';
        }
        for (int i = 0; i < N; i++)
        {
            nn[i] = n[i]-'0';
        }
    }
    else
    {
        for (int i = 0; i < cha; i++)
        {
            nn[i] = 0;
        }
        for (int i = cha; i < N; i++)
        {
            nn[i] = n[i - cha]-'0';
        }
        for (int i = 0; i < N; i++)
        {
            mm[i] = m[i]-'0';
        }
    }
    return cha;

}

void workout(int* mm, int* nn, int* p, int* MAX,int cha)
{
    int num;
    for (int i = 0; i < N; i++)
    {
        if (i < M)
        {
            if ((i + 1) % 2 == 0)
            {
                num = nn[i] - mm[i];
                if (num < 0)
                {
                    num += 10;
                }
            }
            else
            {
                num = (mm[i] + nn[i]) % 13;
            }
            p[i] = num;
        }
        else
        {
            p[i] = MAX[i];
        }
    }
}

void add_MAX(int* MAX, string m, string n, int* mm, int* nn)
{
    if (m.size() > n.size())
    {
        for (int i = 0; i < N; i++)
        {
            MAX[i] = mm[i];
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            MAX[i] = nn[i];
        }
    }
}

void view(int* p)
{
    for (int i = N-1; i > -1; i--)
    {
        switch (p[i])
        {
        case 10:
            cout << "J";
            break;
        case 11:
            cout << "Q";
            break;
        case 12:
            cout << "K";
            break;
        default:
            cout << p[i];
            break;
        }
    }
}

void myprintf(int* p)
{
    for (int i = 0; i < N; i++)
    {
        cout << p[i];
    }
    cout << endl;
}

int main()
{
    string m, n;
    cin >> m >> n;
    find_max(m, n);
    find_min(m, n);
    //1.构建数组
    int* mm;
    mm = (int*)malloc(N * 4);
    int* nn;
    nn = (int*)malloc(N * 4);
    //2.插入数据（包括0末尾的）
    int cha = add_mm_nn(mm, nn, m, n);

    ////测试
    //myprintf(mm);
    //myprintf(nn);

    /*3.计算密码*/
    int* p;
    p = (int*)malloc(N * 4);
    int* MAX;
    MAX = (int*)malloc(N * 4);
    add_MAX(MAX, m, n, mm, nn);
    reverse(&mm[0], &mm[N]);
    reverse(&nn[0], &nn[N]);
    reverse(&MAX[0], &MAX[N]);
    //myprintf(mm);
    //myprintf(nn);
    workout(mm, nn, p, MAX, cha);
    //测试
    /*myprintf(p);*/

    ////4.打印正确密码
    view(p);

    //system("pause");
    ////
    free(mm);
    free(nn);
    free(p);
    free(MAX);
    return 0;
}