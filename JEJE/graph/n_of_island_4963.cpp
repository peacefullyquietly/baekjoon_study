#include<bits/stdc++.h>
#define MAX 51
using namespace std;

int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};

int g[MAX][MAX];
int N, M;

inline void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});
    g[y][x]=0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(g[cy][cx]==0)continue;
            if(cx<0||cy<0||cx>=M||cy>=N)continue;
            g[cy][cx]=0;
            q.push({cx, cy});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1){
        cin>>M>>N;
        if(N==0 && M==0) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>g[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(g[i][j]==1){
                    bfs(j,i);
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }
}