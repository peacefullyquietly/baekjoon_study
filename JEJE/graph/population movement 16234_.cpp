#include<bits/stdc++.h>
#define MAX 51
using namespace std;

int n, l, r, ans = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int v[MAX][MAX];
bool visited[MAX][MAX];
unordered_map<int, vector<pair<int, int>>> m;

bool isRange(int x, int y){
    int tmp = abs(x-y);
    return l <= tmp && tmp <= r;
}

bool bfs(int x, int y){
    queue<pair<int, int>> q;
    vector<pair<int, int>> memo;
    bool moved = false;
    q.push({x, y});
    memo.push_back({x, y});
    visited[y][x] = true;
    while(!q.empty()){
        x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(visited[ny][nx]) continue;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(isRange(v[y][x], v[ny][nx])){
                visited[ny][nx] = true;
                q.push({nx, ny});
                memo.push_back({nx, ny});
                moved = true;
            }
        }
    }
    if(moved){
        int sum = 0;
        for(auto i : memo){
            sum += v[i.second][i.first];
        }
        sum /= memo.size();
        m[sum] = memo;
    }
    return moved;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    while(true){
        
        bool moved = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                moved |= bfs(j, i);
            }
        }
        if(!moved) break;
        ans++;

        for(auto i : m){
            for(auto j : i.second){
                v[j.second][j.first] = i.first;
            }
        }

        memset(visited, false, sizeof(visited));
        m.clear();
    }
    cout << ans << '\n';
}