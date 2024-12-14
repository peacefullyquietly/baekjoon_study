#include<bits/stdc++.h>
#define MAX 500001
using namespace std;

bool visited[MAX][2];
int road[MAX][2];
int N, K;

void bfs(int older){
    queue<pair<int, int>> q;
    q.push({older, 0});
    visited[older][0] = 0;

    while(!q.empty()){
        int pos, cnt;
        tie(pos, cnt) = q.front(); q.pop();     
        if(pos <= 0 || pos > MAX-1) continue;
        if(visited[pos][cnt%2]) continue;
        visited[pos][cnt%2] = true;
        road[pos][cnt%2] = cnt;
        q.push({pos*2, cnt+1});
        q.push({pos+1, cnt+1});
        q.push({pos-1, cnt+1});     
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> N >> K;
    memset(road, 0x3f, sizeof(road));
    bfs(N);

    for(int i = 0; K < MAX; i += 1){
        if(K + i > 500000){
            cout << -1 << '\n';
            return 0;
        }
        K += i;
        for(int j = 0; j <= 1; j++){
            if(i - road[K][j] >= 0 && (i - road[K][j]) % 2 == 0){
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}