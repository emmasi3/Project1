#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void add_v(vector<int>& v,int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
}

void add_s(set<int>& s,const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        s.insert(*it);
    }
}

void add_ms(multiset<int>& ms,const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        ms.insert(*it);
    }
}

void add_count(map<int,int>& m, const set<int>& s, const multiset<int>& ms)
{
    int num;
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        num = ms.count(*it);
        m.insert(make_pair(*it, num));
    }
}

class compare
{
public:
    bool operator()(const pair<int,int> p1,const pair<int,int> p2)const
    {
        return p1.second > p2.second;
    }
};

void 排序(map<int, int>& m,vector<pair<int, int>>& v)
{
    //1.给map 排序--> value 排序
    for (map<int, int>::iterator pos = m.begin(); pos != m.end(); pos++)
    {
        v.push_back(*pos);
    }
    m.clear();
    sort(v.begin(), v.end(), compare());
   ///* 测试*/
   // for (int i = 0; i < v.size(); i++)
   // {
   //     cout << v[i].first << " " << v[i].second << endl;
   // }
}

void save(vector<pair<int, int>>& v,vector<int>& o)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == v[0].second)
        {
            o.push_back(v[i].first);
        }
    }
    //测试
    //for (int i = 0; i < o.size(); i++)
    //{
    //    cout << o[i] << " ";
    //}
}

void myprintf(const map<int, int>& m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int>v;
    //1.放进 v;
    add_v(v, n);
    //2.放进set
    set<int>s;
    add_s(s, v);
    //3.放进m·set
    multiset<int>ms;
    add_ms(ms,v);

    //测试
    /*for_each(ms.begin(), ms.end(), myprintf);*/

    //4.记录次数 <数字，次数>
    map<int, int>m;
    add_count(m, s, ms);

    //测试
    /*myprintf(m);  正常进行排序并打印出了次数（正序）*/

    //5.留下次数最多的（其余都删除）--- 找一个删除一个，不好弄，直接放进新的数组
    vector<pair<int, int>>vv;
    排序(m,vv);
    vector<int>o;//目标容器（装的都是最大的）
    save(vv,o);

    //myprintf(m);

    //6.当次数最多的不止一个时，打印第一个出现的
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < o.size(); j++)
        {
            if (v[i] == o[j])
            {
                cout << o[j];
                return 0;
            }
        }
    }


    system("pause");
    return 0;
}