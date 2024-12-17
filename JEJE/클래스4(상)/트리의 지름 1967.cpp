// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int MAX = 10001;

struct Info{
    int node, w;
}; vector<Info> list[MAX];
bool visited[MAX];

Info bfs(int start)
{
    Info big = {0,0};
    queue<Info> q;
    memset(visited, false, sizeof visited);
    
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty())
    {
        int node = q.front().node, weight = q.front().w;
        q.pop();
        
        if(weight > big.w) big = {node, weight};
        
        for(auto &i : list[node])
        {
            if(visited[i.node]) continue;
            q.push({i.node, weight+i.w});
            visited[i.node] = true;
        }
    }
    return big;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    tc -= 1;
    while(tc--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        list[a].push_back({b,w});
        list[b].push_back({a,w});
    }
    cout << bfs(bfs(1).node).w << '\n';
}

// 자율발표 보고서
// 물리 보고서
// ai 세특
// 독?서