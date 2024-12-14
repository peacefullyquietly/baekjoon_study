// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> tree(1001, vector<int>(1001, 0));
bool visit_dfs[1001] = { false };
bool visit_bfs[1001] = { false };
int M, N, S;

void dfs(int s)
{
    cout << s << ' ';
    visit_dfs[s] = true;
    for (int i = 1; i <= M; i++)
    {
        if (visit_dfs[i] || tree[s][i] == 0) 
        {
            continue;
        }
        dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> S;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x][y] = tree[y][x] = 1;
    }
    dfs(S);
}