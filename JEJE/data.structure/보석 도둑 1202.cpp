// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;
int N, K;

struct Info{
    int m, v;
};
struct Comp{
    bool operator() (const Info &a, const Info &b) const
    {
        if(a.m == b.m) return a.v < b.v;
        return a.m > b.m;
    }
};

priority_queue<Info,vector<Info>,Comp> pq;
priority_queue<int,vector<int>,greater<int>> bag;
priority_queue<int> add;
/*
N: 보석 개수
K: 가방 개수
M: 무개
V: 가격
C: 최대 무개
*/


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    while(N--)
    {
        int  m, v;
        cin >> m >> v;
        pq.push({m, v});
    }
    for(int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        bag.push(n);
    }

    unsigned long long ans = 0;
    while(!bag.empty())
    {
        int C = bag.top(); bag.pop();
        while(!pq.empty())
        {
            int m = pq.top().m, v = pq.top().v;
            if(m > C) break;
            pq.pop();
            add.push(v);
        }
        if(!add.empty())
        {
            ans += add.top();
            add.pop();
        }
    }
    
    cout << ans << '\n';
}
/*
9 5
4 5
4 9<
4 10<
8 55<
14 20
9 15
8 55<
8 5
11 54<
10 -> 55
5 -> 9
4 -> 10
15 -> 55
20 -> 54
*/