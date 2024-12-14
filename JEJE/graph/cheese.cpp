#include<iostream>
#include<queue>
#define p pair<int, int>
#define x first
#define y second
using namespace std;

int n, m, cheese_cnt = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool cheese[102][102];
bool visited[102][102];
queue<p> _q[2];

void bfs(queue<p> &q, queue<p> &tmpq){

    while(!q.empty()){
        int x = q.front().x, y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(visited[ny][nx]) continue;
            if(nx < 0 || ny < 0 || nx > m+1 || ny > n+1) continue;
            visited[ny][nx] = true;
            if(cheese[ny][nx]){
                cheese_cnt--;
                tmpq.push({nx, ny});
            }else{
                q.push({nx, ny});
            }
        }
    }
}

p melt(){
    int time = 0, cheese_last = 0;
    while(cheese_cnt){
        int idx = time%2;
        int tmpidx = (time+1)%2;
        cheese_last = cheese_cnt;
        bfs(_q[idx], _q[tmpidx]);
        time++;
    }
    return {time, cheese_last};
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> cheese[i][j];
            if(cheese[i][j]) cheese_cnt++;
        }
    }

    for(int i = 0; i <= n+1; i++){
        visited[i][0] = visited[i][m+1] = true;
        _q[0].push({0, i});
        _q[0].push({m+1, i});
    }
    for(int i = 0; i <= m+1; i++){
        visited[0][i] = visited[n+1][i] = true;
        _q[0].push({i, 0});
        _q[0].push({i, n+1});
    }

    p ans = melt();
    cout << ans.first << '\n' << ans.second << '\n';
}