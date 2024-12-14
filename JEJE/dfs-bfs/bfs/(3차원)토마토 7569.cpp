// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int dx[] = {0,1,0,-1,0,0};
int dy[] = {-1,0,1,0,0,0};
int dh[] = {0,0,0,0,-1,1};
int m, n, h, v[100][100][100];

struct Info{
    int x, y, h, cnt;
}; queue<Info> q;
//m:가로 n:세로 h:높이

bool check()
{
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < m; l++)
            {
                if(v[i][j][l] == 0) return false;
            }
        }
    }
    return true;
}

int bfs()
{
    int last = 0;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, z = q.front().h, cnt = q.front().cnt;
        last = cnt;
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int cx = x+dx[i];
            int cy = y+dy[i];
            int ch = z+dh[i];
            if(cx < 0 || cx >= m || cy < 0 || cy >= n || ch < 0 || ch >= h) continue;
            if(v[ch][cy][cx] != 0) continue;
            v[ch][cy][cx] += 1;
            q.push({cx, cy, ch, cnt+1});
        }
    }
    return last;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < m; l++)
            {
                cin >> v[i][j][l];
                if(v[i][j][l] == 1)q.push({l,j,i,0});
            }
        }
    }
    int answer = bfs();
    if(check()) cout << answer;
    else cout << -1;
    cout << '\n';
}