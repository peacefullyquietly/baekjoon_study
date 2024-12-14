#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
#define INF 1000000000
using namespace std;

int d[MAX], N, M, starting, ending;
vector<pair<int,int>> list[MAX];

int dada()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0, starting});
    while(!pq.empty())
    {
        int w = pq.top().first, n = pq.top().second;
        pq.pop();
        if(w > d[n]) continue;
        for(auto &i : list[n])
        {
            if(d[i.second] > i.first + w)
            {
                d[i.second] = i.first + w;
                pq.push({i.first + w, i.second});
            }
        }
    }
    return d[ending];
}

int main()
{
    cin >> N >> M;
    while(M--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        list[a].push_back({w, b});
    }
    for(int i = 0; i <= N; i++)d[i] = INF;
    cin >> starting >> ending;
    cout << dada() << '\n';
}