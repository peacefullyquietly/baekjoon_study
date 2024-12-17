// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#define MAX 9
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[MAX][MAX];
vector<pair<int, int>> virus;
int n, m, ans = 0;

void check(int _map[MAX][MAX]) {
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }
    while (!q.empty()) {
        int _x = q.front().first, _y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = _x + dx[i];
            int y = _y + dy[i];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (_map[y][x] == 0) {
                _map[y][x] = 2;
                q.push({ x,y });
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_map[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    ans = max(ans, cnt);
}

void dfs(int cnt) {
    if (cnt == 3) {
        int tmp[MAX][MAX];
        memcpy(tmp, map, sizeof(map));
        check(tmp);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                dfs(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back({ j, i });
            }
        }
    }
    dfs(0);
    cout << ans << '\n';
}