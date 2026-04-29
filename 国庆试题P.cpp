#include <bits/stdc++.h>
using namespace std;

int N = 0;//最大数位数
int M = 0;//最数小位数
void find_max(unsigned long long m, unsigned long long n)
{
    if (m > n)
    {
        while (m > 0)
        {
            m /= 10;
            N++;
        }
    }
    else
    {
        while (n > 0)
        {
            n /= 10;
            N++;
        }
    }
}

void find_min(unsigned long long m, unsigned long long n)
{
    if (m < n)
    {
        while (m > 0)
        {
            m /= 10;
            M++;
        }
    }
    else
    {
        while (n > 0)
        {
            n /= 10;
            M++;
        }
    }
}

void add_mm_nn(int *mm,int *nn, unsigned long long m, unsigned long long n)
{
    for (int i = 0; i < N ; i++)
    {
        if (m == 0)
        {
            mm[i] = 0;
            continue;
        }
        mm[i] = m % 10;
        m /= 10;
    }

    for (int i = 0; i < N; i++)
    {
        if (n == 0)
        {
            nn[i] = 0;
            continue;
        }
        nn[i] = n % 10;
        n /= 10;
    }
}

void workout(int* mm, int* nn, int* p,int *MAX)
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

void add_MAX(int* MAX, unsigned long long m, unsigned long long n, int* mm, int* nn)
{
    if (m > n)
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
    for (int i = N-1; i>-1 ; i--)
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

//void myprintf(int* p)
//{
//    for (int i = 0; i < N; i++)
//    {
//        cout << p[i];
//    }
//    cout << endl;
//}

int main()
{
   unsigned long long m, n;
    cin >> m >> n;
    find_max(m, n);
    find_min(m, n);
    //1.构建数组
    int* mm;
    mm = (int*)malloc(N * 4);
    int* nn;
    nn = (int*)malloc(N * 4);
    //2.插入数据（包括0末尾的）
    add_mm_nn(mm, nn, m, n);

    //测试
    //myprintf(mm);
    //myprintf(nn);

    //3.计算密码
    int* p;
    p = (int*)malloc(N * 4);
    int* MAX;
    MAX = (int*)malloc(N * 4);
    add_MAX(MAX, m, n, mm, nn);
    workout(mm, nn, p,MAX);
    //测试
    //myprintf(p);

    //4.打印正确密码
    view(p);
    
    system("pause");
    //
    free(mm);
    free(nn);
    free(p);
    free(MAX);
    return 0;
}