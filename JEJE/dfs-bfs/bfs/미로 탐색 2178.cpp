#include<iostream>
#include<queue>
#include<set>
using namespace std;

set<pair<int,int>> visit;
struct Info{
    int x, y, cnt;
};queue<Info> q;

int N, M, v[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs()
{
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        visit.insert({x,y});
        //cout << x << " " << y << '\n';
        q.pop();
        if(x == M-1 && y == N-1) return cnt;
        for(int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(visit.count({cx,cy}) || v[cy][cx] == 0) continue;
            if(cx < 0 || cx >= M || cy < 0 || cy >= N) continue;
            visit.insert({cx,cy});
            q.push({cx, cy, cnt+1});
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    char num;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num;
            n = num - '0';
            v[i][j] = n;
        }
    }
    q.push({0, 0, 1});
    cout << bfs() << '\n';
}