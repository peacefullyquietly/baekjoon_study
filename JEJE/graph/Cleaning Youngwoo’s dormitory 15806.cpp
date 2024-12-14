// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define p tuple<int, int, int>
using namespace std;

int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};
int N, M, K, T;
int room[301][301][2];
bool visited[301][301][2];
queue<p> Q[2];

void bfs(int n) {
    queue<p>& q = Q[n];
    while (!q.empty()) {
        bool isGoja = true;
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[ny][nx][n]) continue;   
            isGoja = false;
            visited[ny][nx][n] = true;
            room[ny][nx][n] = cnt;
            q.push({ nx, ny, cnt + 1 });
        }
        if(isGoja) room[y][x][n] = 1e9;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K >> T;

    memset(room, 0x3f, sizeof(room));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Q[(a + b) % 2].push({ a,b,1 });
        visited[b][a][(a + b) % 2] = true;
        room[b][a][(a + b) % 2] = 0;
    }

    bfs(0);
    bfs(1);

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        for (int i = 0; i <= 1; i++) {
            int flag = room[b][a][i];
            if (flag <= T && (T - flag) % 2 == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}