#include<iostream>
#include<queue>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int v[1000][1000], m, n;

struct Info{
    int x, y, cnt;
};
queue<Info> q;

bool check()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 0) return false;
        }
    }
    return true;
}

int bfs()
{
    int last;
    while(!q.empty())
    {
        int x=q.front().x, y=q.front().y, cnt=q.front().cnt;
        last = cnt;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int cx = x+dx[i], cy = y+dy[i];
            if(cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
            if(v[cy][cx] == -1 || v[cy][cx] > 0)continue;
            q.push({cx, cy, cnt+1});
            v[cy][cx] += 1;
        }
    }   
    return last;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        {
            cin >> t;
            if(t == 1)q.push({j, i, 0});
            v[i][j] = t;
        }
    }
    t = bfs();
    if(check()) cout << t;
    else cout << -1;
    cout << '\n';
    return 0;
}