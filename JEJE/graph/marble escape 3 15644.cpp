// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

typedef struct _Info {
    int bx, by;
    int rx, ry;
    int cnt;
    string log;
}Info;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

char board[11][11];
bool visited[11][11][11][11];

void move(int& x, int& y, int& cnt, int& i) {
    while (board[y + dy[i]][x + dx[i]] != '#' &&
        board[y][x] != 'O') {
        x += dx[i];
        y += dy[i];
        cnt++;
    }
}

void bfs(int rx, int ry, int bx, int by) {
    queue<Info> q;
    q.push({ bx, by, rx, ry, 0, "" });
    visited[bx][by][rx][ry] = true;

    while (!q.empty()) {
        int rx = q.front().rx, ry = q.front().ry;
        int bx = q.front().bx, by = q.front().by;
        int cnt = q.front().cnt;
        string log = q.front().log;
        q.pop();

        for (int i = 0; i < 4; i++) {
            Info nxt;
            nxt.rx = rx, nxt.ry = ry;
            nxt.bx = bx, nxt.by = by;
            nxt.cnt = cnt + 1;
            nxt.log = log;

            if (nxt.cnt > 10) {
                break;
            }

            //marble move
            int rCnt = 0, bCnt = 0;
            move(nxt.rx, nxt.ry, rCnt, i);
            move(nxt.bx, nxt.by, bCnt, i);

            if (board[nxt.by][nxt.bx] == 'O') continue;
            if (board[nxt.ry][nxt.rx] == 'O') {
                if (i == 0) nxt.log += 'D';
                else if (i == 1) nxt.log += 'U';
                else if (i == 2) nxt.log += 'R';
                else if (i == 3) nxt.log += 'L';
                cout << nxt.cnt << '\n';
                cout << nxt.log << '\n';
                return;
            }

            //check
            if (nxt.rx == nxt.bx && nxt.ry == nxt.by) {
                if (rCnt > bCnt) {
                    nxt.rx -= dx[i];
                    nxt.ry -= dy[i];
                }
                else {
                    nxt.bx -= dx[i];
                    nxt.by -= dy[i];
                }
            }

            if (visited[nxt.bx][nxt.by][nxt.rx][nxt.ry]) continue;

            //log
            if (i == 0) nxt.log += 'D';
            else if (i == 1) nxt.log += 'U';
            else if (i == 2) nxt.log += 'R';
            else if (i == 3) nxt.log += 'L';

            visited[nxt.bx][nxt.by][nxt.rx][nxt.ry] = true;
            q.push(nxt);
        }
    }

    cout << -1 << '\n';

}

int main() {
    cin >> n >> m;
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                rx = j;
                ry = i;
            }
            else if (board[i][j] == 'B') {
                bx = j;
                by = i;
            }
        }
    }

    bfs(rx, ry, bx, by);
}