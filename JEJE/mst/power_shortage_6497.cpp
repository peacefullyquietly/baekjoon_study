// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
typedef pair<int, int> p;

int V, E, ans, u[MAX];
struct Info{
    int a, b, w;
    bool operator <(const Info &other) const{ return w > other.w;}
}; priority_queue<Info> pq;

int find(int n)
{
    if(u[n] == n) return n;
    else return u[n] = find(u[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(a<b)u[b] = a;
    else u[a] = b; 
}

int mst()
{
    while(!pq.empty())
    {
        int a = pq.top().a, b = pq.top().b, w = pq.top().w;
        pq.pop();
        if (find(a) != find(b))
        {
            ans += w;
            merge(a, b);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1){
        ans = 0;
        cin >> V >> E;
        if(V == 0 && E == 0) break;
        for(int i = 1; i <= V; i++) u[i] = i;
        int ans = 0;
        while(E--)
        {
            int a, b, w;
            cin >> a >> b >> w;
            ans += w;
            pq.push({a, b, w});
        }
        cout << ans-mst() << '\n';
    }
}