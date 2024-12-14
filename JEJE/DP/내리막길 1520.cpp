#include<iostream>
#include<cstring>
#define MAX 501///////////////////
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int n, m, v[MAX][MAX] ,dp[MAX][MAX];
bool visited[MAX][MAX];
// x == m y == n
int dfs(int x, int y)
{
    if(dp[y][x] > -1) return dp[y][x];
    else if(x == m-1 && y == n-1) return 1;
    else if(visited[y][x]) return 0;
    visited[y][x] = true;
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        //cout << nx << ":" << ny << "\n";
        if(v[ny][nx] >= v[y][x]) continue;
        dp[y][x] += dfs(nx, ny);
    }
    visited[y][x] = false;
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        cin >> v[i][j];
    }
    memset(dp,-1,sizeof dp);
    cout << dfs(0,0) << '\n';

    // cout << "==============\n";

    // for(auto &i : dp){
    //     for(auto &j : i) cout << j << ' ';
    //     cout << '\n';
    // }
}
