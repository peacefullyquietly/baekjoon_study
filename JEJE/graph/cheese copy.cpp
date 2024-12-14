// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#define p pair<int, int>
#define x first
#define y second
using namespace std;

int n, m, cheese_cnt = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cheese[102][102];
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
            if(cheese[ny][nx] == 3){
                cheese_cnt--;
                tmpq.push({nx, ny});
                visited[ny][nx] = true;
            }else{
                if(cheese[ny][nx] == 0){
                    visited[ny][nx] = true;
                }else{
                    cheese[ny][nx] += 1;
                }
                q.push({nx, ny});
            }
        }
    }
}

void first_bfs(queue<p> &q, queue<p> &tmpq){
    while(!q.empty()){
        int x = q.front().x, y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(visited[ny][nx]) continue;
            if(nx < 0 || ny < 0 || nx > m+1 || ny > n+1) continue;
            visited[ny][nx] = true;
            if(!cheese[ny][nx]) tmpq.push({nx, ny});
        }
    }
}

int melt(){
    int time = 0;
    first_bfs(_q[1], _q[0]);
    while(cheese_cnt){
        int idx = time%2;
        int tmpidx = (time+1)%2;
        bfs(_q[idx], _q[tmpidx]);
        time++;
    }
    return time;
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
        _q[1].push({0, i}); //tmpq에 넣음
        _q[1].push({m+1, i});
    }
    for(int i = 0; i <= m+1; i++){
        visited[0][i] = visited[n+1][i] = true;
        _q[1].push({i, 0});
        _q[1].push({i, n+1});
    }

    cout << melt() << '\n';
}