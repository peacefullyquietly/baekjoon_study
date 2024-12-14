// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#include<set>
using namespace std;

int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int v[100][100];

struct Info{
    int x, y;
};

set<pair<int,int>> visit;

void rgb(int x, int y)
{
    queue<Info> q;

    q.push({x,y});
    visit.insert({x,y});

    int color = v[y][x];

    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        visit.insert({x, y});
        for(int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(visit.count({cx,cy}) || v[cy][cx] != color) continue;
            if(cx < 0 || cx >= N || cy < 0 || cy >= N) continue;
            visit.insert({cx, cy});
            q.push({cx, cy});
        }
    }
}

void rrb(int x, int y)
{
    queue<Info> q;

    q.push({x,y});
    visit.insert({x,y});

    int color = abs(v[y][x]);

    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        visit.insert({x, y});
        for(int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(visit.count({cx,cy}) || abs(v[cy][cx]) != color) continue;
            if(cx < 0 || cx >= N || cy < 0 || cy >= N) continue;
            visit.insert({cx, cy});
            q.push({cx, cy});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    char num;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            if(num == 'R') n=1;
            else if(num == 'G') n=-1;
            else n=0;
            v[i][j] = n;
        }
    }

    int rg = 0, rr = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit.count({j,i}))
            {
                rgb(j,i);
                rg += 1;
            }
        }
    }
    visit.clear();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit.count({j,i}))
            {
                rrb(j,i);
                rr += 1;
            }
        }
    }
    cout << rg << ' ' << rr << '\n';
}