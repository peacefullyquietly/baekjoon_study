// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
int s, v[MAX];
bool visited[MAX];

struct Info{
    int n, cnt;
};

int bfs()
{
    queue<Info> q;
    q.push({0, 0});
    visited[0] = true;
    while(!q.empty())
    {
        int n = q.front().n, cnt = q.front().cnt;
        q.pop();
        if(n == s-1) return cnt;

        for(int i = 1; i <= v[n]; i++)
        {
            int cn = n+i;
            if(cn < 0 || cn >= s) continue;
            if(visited[cn]) continue;
            q.push({cn, cnt+1});
            visited[cn] = true;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    for(int i = 0; i < s; i++) cin >> v[i];
    cout << bfs() << '\n';
}