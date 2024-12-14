// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<set>

using namespace std;

int bottle[3];
set<pair<pair<int, int>, int>> visited;
set<int> ans;

void dfs(int v[])
{
    cout << "==================\n";
    visited.insert({ {v[0], v[1]}, v[2] });
    if (v[0] == 0)ans.insert(v[2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            cout << i << ' ' << j;
            if (v[i] + v[j] > bottle[j]) {
                v[i] += v[j] - bottle[j];
                v[j] = bottle[j];
            }
            else {
                v[j] += v[i];
                v[i] = 0;
            }
            // if (visited.count({ {v[0], v[1]}, v[2] })) continue;
            // for (int i = 0; i < 3; i++) cout << v[i] << ' ';
            // cout << '\n';
            // dfs(v);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> bottle[0] >> bottle[1] >> bottle[2];
    int v[3] = { 0, 0, bottle[2] };
    dfs(v);
    for (auto& i : ans) cout << i << ' ';
    cout << '\n';
}