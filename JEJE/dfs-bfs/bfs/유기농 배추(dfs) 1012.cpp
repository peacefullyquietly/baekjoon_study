#include<iostream>
#include<cstring>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool plant[50][50], visit[50][50];

int M, N, K;

void dfs(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx < 0 || cx >= M || cy < 0 || cy >= N) continue;
        if(!plant[cy][cx] || visit[cy][cx]) continue;
        visit[cy][cx] = true;
        dfs(cx,cy);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int answer = 0;
        memset(plant, false, sizeof plant);
        memset(visit, false, sizeof visit);
        cin >> M >> N >> K;
        while(K--)
        {
            int a, b;
            cin >> a >> b;
            plant[b][a] = true;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
            {
                if(!plant[i][j] || visit[i][j]) continue;
                visit[i][j] = true;
                answer += 1;
                dfs(j, i);
            }
        }
        cout << answer << '\n';
    }
}