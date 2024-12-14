#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int N, color_flag = 2;
int g[MAX][MAX];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void fill_color(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    g[y][x] = color_flag;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int cx = x+dx[i];
            int cy = x+dy[i];
            if(g[cy][cx]==color_flag || g[cy][cx]==0) continue;
            if(cx<0||cy<0||cx>=N||cy>=N) continue;
            g[cy][cx]=color_flag;
            q.push({cx,cy});
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> g[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if()
        }
    }
}