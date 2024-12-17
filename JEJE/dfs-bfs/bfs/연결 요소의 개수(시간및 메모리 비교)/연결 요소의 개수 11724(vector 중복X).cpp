// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[1001], s;
bool visit[1001];
int visit_node_cnt = 0;

void dfs(int node)
{
    visit[node] = true;
    visit_node_cnt += 1;
    for(auto &i:v[node])
    {
        if(!visit[i]) dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, a, b, dab = 0;
    cin >> N >> M;
    while(M--)

    {
        cin >> a >> b;
        s.push_back(a);
        s.push_back(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    s.erase(unique(s.begin(), s.end()),s.end());
    for(auto &i : s)
    {
        if(!visit[i])
        {
            dab += 1;
            dfs(i);
        }
    }
    cout << dab+(N-visit_node_cnt) << '\n';
}