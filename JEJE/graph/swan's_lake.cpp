// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#define MAX 1501
#define p pair<int,int>
#define x first
#define y second
using namespace std;

p swan;
queue<p> wq, sq, tmp_wq, tmp_sq;
int R, C;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char map[MAX][MAX];
bool visit[MAX][MAX];

bool swanBfs(){
    while(!sq.empty()){
        int x = sq.front().x, y = sq.front().y;
        sq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if(visit[ny][nx]) continue;
            
            visit[ny][nx] = true;
            if(map[ny][nx] == 'X'){
                tmp_sq.push({nx, ny});
            } else if(map[ny][nx] == '.'){
                sq.push({nx, ny});
            } else if(map[ny][nx] == 'L'){
                return true;
            }
        }
    }
    return false;
}

void melt(){
    while(!wq.empty()){
        int x = wq.front().x, y = wq.front().y;
        wq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if(map[ny][nx] == 'X'){
                map[ny][nx] = '.';
                tmp_wq.push({nx, ny});
            }
        }
    }
}

int isMeet(p swan){
    sq.push(swan);
    visit[swan.y][swan.x] = true;
    
    int day = 0;
    while(!swanBfs()){
        melt();
        swap(wq, tmp_wq);
        swap(sq, tmp_sq);
        day++;
    }
    return day;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == '.'){
                wq.push({j, i});
            } else if(map[i][j] == 'L'){
                wq.push({j, i});
                swan = {j, i};
            }
        }
    }

    cout << isMeet(swan) << '\n';
}