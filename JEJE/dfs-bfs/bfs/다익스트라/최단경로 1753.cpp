#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> p;
const int MAX = 20001, INF = 2000000000;
int d[MAX], V, E, start;
vector<p> list[MAX];
priority_queue<p,vector<p>,greater<p>> pq;

void da()
{
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty())
    {
        int now = pq.top().second, distance = pq.top().first;
        pq.pop();
        if(d[now] < distance) continue;
        for(auto &i : list[now])
        {
            int next = i.second, add = i.first;
            if(d[next] > distance + add)
            {
                d[next] = distance + add;
                pq.push({distance + add, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int u, v, w;

    cin >> V >> E >> start;
    while(E--)
    {
        cin >> u >> v >> w;
        list[u].push_back({w, v});
    }
    for(int i = 0; i <= V; i++) d[i] = INF;
    da();
    for(int i = 1; i <= V; i++)
    {
        if(d[i] < INF) cout << d[i];
        else cout << "INF";
        cout << '\n';
    }
}