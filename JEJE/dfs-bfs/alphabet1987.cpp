#include<iostream>
using namespace std;

bool alpha[27];
char map[21][21];
int R, C, ans = 0;
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};

int AlphatoIndex(char abc){
    return abc - 'A';
}

void dfs(int x, int y, int cnt){
    alpha[AlphatoIndex(map[y][x])] = true;
    ans = max(ans, cnt);
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
        if(alpha[AlphatoIndex(map[ny][nx])]) continue;
        dfs(nx, ny, cnt+1);
    }
    alpha[AlphatoIndex(map[y][x])] = false;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    dfs(0, 0, 1);
    cout << ans << '\n';
}