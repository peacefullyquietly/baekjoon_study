// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 51;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int sx, sy, v[MAX][MAX], dp[MAX][MAX];
bool visited[MAX][MAX], roop;

int dfs(int x, int y)
{
    if(x < 0 || x >= sx || y < 0 || y>=sy || v[y][x] == 0) return 0;
    if(roop||visited[y][x])
    {
        roop = true;
        return -1;
    }
    if(dp[y][x] > -1) return dp[y][x];
    visited[y][x] = true;
    for(int i = 0; i < 4; i++)
    {
        int cx = x + dx[i]*v[y][x];
        int cy = y + dy[i]*v[y][x];
        dp[y][x] = max(dp[y][x], dfs(cx, cy)+1);
    }
    visited[y][x] = false;

    if(roop) return -1;
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> sy >> sx;
    char num;
    for(int i = 0; i < sy; i++)
    {
        for(int j = 0; j < sx; j++)
        {
            cin >> num;
            if(num == 'H') v[i][j] = 0;
            else v[i][j] = num-'0';
        }
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0,0) << '\n';
}