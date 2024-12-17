// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int oh[1000001];

int bfs(int F, int S, int G, int U, int D)
{
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({S, cnt});
    while(!q.empty())
    {
        S = q.front().first, cnt = q.front().second;
        if(S==G) return cnt;
        q.pop();
        if(oh[S])continue;
        if(S+U <= F)q.push({S+U, cnt+1});
        if(S-D > 0)q.push({S-D, cnt+1});
        oh[S] = true;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int F, S, G, U, D;
    cin >>  F >> S >> G >> U >> D;
    int answer = bfs(F, S, G, U, D);
    if(answer > 0)cout << answer;
    else cout << "use the stairs";
    cout << '\n';
}