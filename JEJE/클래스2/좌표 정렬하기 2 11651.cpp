#include<iostream>
#include<set>
using namespace std;

struct Sort{
    bool operator() (const pair<int,int> a, const pair<int, int> b) const
    {
        if(a.second == b.second)return a.first < b.first;
        else return a.second < b.second;
    }
};

int main()
{
    int tc, a, b;
    set<pair<int,int>, Sort> s;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b;
        s.insert({a, b});
    }
    for(auto &i : s) cout << i.first << ' ' << i.second << '\n';
}