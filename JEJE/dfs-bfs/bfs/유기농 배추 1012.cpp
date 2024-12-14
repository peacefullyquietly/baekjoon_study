#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
struct Info{
    int x,y;
}; queue<Info> q;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int M, N, K;
bool bath[50][50];
bool use[50][50];

void bfs()
{
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(cx < 0 || cx >= M || cy < 0 || cy >= N) continue;
            if(!bath[cy][cx] || use[cy][cx]) continue;
            use[cy][cx] = true;
            q.push({cx, cy});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b, answer = 0;
        memset(bath, false, sizeof bath);
        memset(use, false, sizeof use);
        cin >> M >> N >> K;
        while(K--)
        {
            cin >> a >> b;
            bath[b][a] = true;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
            {
                if(!bath[i][j] || use[i][j]) continue;
                q.push({j,i});
                use[i][j] = true;
                bfs();
                answer += 1;
            }
        }
        cout << answer << '\n';
    }
}