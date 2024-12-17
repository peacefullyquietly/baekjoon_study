// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int tc;

int s[26][26];
vector<int> v;
set<pair<int,int>> visit;

struct QInfo{
    int x, y;
};

void bfs(int x, int y)
{
    int cnt = 1;
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
            if(!(!visit.count({cx,cy}) && s[cy][cx] == 1)) continue;
            if(cx < 0 || cx >= tc || cy < 0 || cy >= tc) continue;
            q.push({cx, cy});
            visit.insert({cx,cy});
            cnt += 1;
        }
    }
    v.push_back(cnt);
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
            s[i][j] = n;
        }
    }

    for(int i = 0; i < tc; i++){
        for(int j = 0; j < tc; j++){
            if(!visit.count({j,i}) && s[i][j] == 1)
            {
                cnt += 1;
                int now_vnode = visit.size();
                bfs(j,i);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for(auto &i : v) cout << i << '\n';    
}