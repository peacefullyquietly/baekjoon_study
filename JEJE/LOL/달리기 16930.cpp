#define MAX 1002
#include<iostream>
#include<queue>
using namespace std;
int n, m, k, ans_x, ans_y;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
char v[MAX][MAX];
bool visited[MAX][MAX];

typedef struct _Info{
    int x, y, cnt;
} Info;

int bfs(int x, int y)
{
    queue<Info> q;
    q.push({x,y,0});
    visited[y][x] = true;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        q.pop();

        if(ans_x == x && ans_y == y) return cnt;

        for(int i=0; i<4; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                int cx = x+dx[i]*j;
                int cy = y+dy[i]*j;
                if(cx <= 0 || cy <= 0 || cx > m || cy > n) break;
                if(visited[cy][cx] || v[cy][cx] == '#') break;
                q.push({cx,cy,cnt+1});
                visited[cy][cx] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int x, y;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
        }
    }
    cin >> y >> x >> ans_y >> ans_x;
    cout << bfs(x,y) << '\n';
}