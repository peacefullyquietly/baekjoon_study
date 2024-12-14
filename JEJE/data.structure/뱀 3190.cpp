#include<iostream>
#include<deque>
#include<queue>
#define MAX 101
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N, K, L;
bool visited[MAX][MAX], apple[MAX][MAX];
char turn[99990];
struct Info{
    int x, y, cnt;
}; queue<Info> q;

int dosgame()
{
    q.push({1, 1, 0});
    visited[1][1] = true;
    int dir = 0;
    while(1)
    {
        int hx = q.back().x, hy = q.back().y, tx = q.front().x, ty = q.front().y, cnt = q.back().cnt;
        if(hx <= 0 || hx > N || hy <= 0 || hy > N) return cnt;
        
        if (turn[cnt] == 'L'){
            dir = (dir+3)%4;
        }else if (turn[cnt] == 'D'){
            dir = (dir+1)%4;
        }
        
        int nx = hx + dx[dir];
        int ny = hy + dy[dir];
        if(visited[ny][nx]) return cnt+1;
        q.push({nx, ny, cnt+1});
        visited[ny][nx] = true;
        
        if(!apple[hy][hx]) //만약 사과가 없다면
        {
            visited[ty][tx] = false;
            q.pop();
        }else apple[hy][hx] = false;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    cin >> K;
    while(K--)
    {
        int x, y;
        cin >> y >> x;
        apple[y][x] = true;
    }
    cin >> L;
    while(L--)
    {
        int a;
        cin >> a;
        cin >> turn[a];
    }
    cout << dosgame() << '\n';
}