#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

vector<int> v[1001];
bool use[1001];


void dfs(int node)
{
    use[node] = true;
    cout << node << ' ';
    for(int i = 0; i < v[node].size(); i++)
    {
        int will_visit = v[node][i];
        if(!use[will_visit])
        {
            dfs(will_visit);
        }
    }
    return;
}

void bfs(int node)
{
    queue<int> q;
    use[node] = true;
    q.push(node);
    while(!q.empty())
    {
        node = q.front();
        cout << node << ' ';
        q.pop();
        for(int i = 0; i < v[node].size(); i++)
        {
            int will_visit = v[node][i];
            if(!use[will_visit])
            {
                use[will_visit] = true;
                q.push(will_visit);
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //n:정점의 개수, m:간선의 개수, v:star node;
    int n, m, start;
    use[0] = true;
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++)
    {
        int go, to;
        cin >> go >> to;
        v[go].push_back(to);
        v[to].push_back(go);
    }
    for(int i = 0; i < n+1; i++) sort(v[i].begin(), v[i].end());
    dfs(start);
    cout << "\n";
    memset(use, false, sizeof(use));
    bfs(start);
    cout << '\n';
    return 0;
}