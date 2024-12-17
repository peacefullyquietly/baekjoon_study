// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100001;

vector<int> list[MAX];
queue<int> q;
bool visited[MAX];
int parent[MAX];

void findP()
{
    q.push(1);
    visited[1] = true;
    while(!q.empty())
    {
        int node = q.front(); q.pop();
        for(auto &i : list[node])
        {
            if(visited[i]) continue;
            parent[i] = node;
            q.push(i);
            visited[i] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    tc -= 1;
    for(int i = 0; i < tc; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    tc += 1;
    findP();
    //cout << "work\n";
    for(int i = 2; i <= tc; i++) cout << parent[i] << '\n';
}