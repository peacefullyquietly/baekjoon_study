// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<set>
#include<queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int tc;

set<pair<int,int>> s;
set<pair<int,int>> visit;
multiset<int> out;

struct QInfo{
    int x, y;
};

void bfs(int x, int y)
{
    queue<QInfo> q;
    q.push({x, y});
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        visit.insert({x,y});
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(!(!visit.count({cx,cy}) && s.count({cx,cy}))) continue;
            if(cx < 0 || cx >= tc || cy < 0 || cy >= tc) continue;
            q.push({cx, cy});
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, cnt = 0;
    char num;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        for(int j = 0; j < tc; j++){
            cin >> num;
            n = num - '0';
            if(n == 1)s.insert({j,i});
        }
    }

    for(int i = 0; i < tc; i++){
        for(int j = 0; j < tc; j++){
            if(!visit.count({j,i}) && s.count({j,i}))
            {
                cnt += 1;
                int now_vnode = visit.size();
                bfs(j,i);
                out.insert(visit.size() - now_vnode);
            }
        }
    }
    cout << cnt << '\n';
    for(auto &i : out) cout << i << '\n';    
}