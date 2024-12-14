// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

typedef struct _Info{
    int x, y;
}Info;queue<Info> q;

int sy, sx, v[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int start_x, int start_y)
{
    q.push({start_x, start_y});
    visited[start_y][start_x] = true;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> sy >> sx;
    for(int i = 0; i < sy; i++) for(int j = 0; j < sx; j++)
    {
        cin >> v[i][j];
    }

}