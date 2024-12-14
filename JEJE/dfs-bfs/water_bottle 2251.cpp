#include<iostream>
#include<set>

using namespace std;

int bottle[3];
set<pair<int, int>> visited;
set<int> ans;

void dfs(int v[3])
{
    visited.insert({v[0], v[1]});

    if (v[0] == 0)ans.insert(v[2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;

            int next[3] = { v[0], v[1], v[2] };

            if (v[i] + v[j] > bottle[j]) {
                next[i] -= bottle[j] - v[j];
                next[j] = bottle[j];
            }
            else {
                next[i] = 0;
                next[j] += v[i];
            }

            if (visited.count({next[0], next[1]})) continue;
            dfs(next);
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