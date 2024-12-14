#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 100001;

struct Info{
    int node, weight;
};vector<Info> list[MAX];
bool visited[MAX];

Info bfs(int start)
{
    queue<Info> q;
    memset(visited, false, sizeof visited);
    Info big = {0,0};

    q.push({start,0});
    visited[start] = true;
    
    while(!q.empty())
    {
        int node = q.front().node, weight = q.front().weight;
        q.pop();

        if(weight > big.weight) big = {node, weight};

        for(auto &i : list[node])
        {
            if(visited[i.node]) continue;
            visited[i.node] = true;
            q.push({i.node,weight + i.weight});
        }
    }
    return big;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        while(1)
        {
            int a;
            cin >> a;
            if(a == -1) break;
            int b;
            cin >> b;
            list[n].push_back({a, b});
        }
    }
    cout << bfs(bfs(1).node).weight << '\n';
}