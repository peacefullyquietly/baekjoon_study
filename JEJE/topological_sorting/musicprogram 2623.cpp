// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> lIst[1001], ans;
int cnt[1001];

void topological_sort() {

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) {
            ans.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto& i : lIst[node]) {
            cnt[i]--;
            if (cnt[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        vector<int> tmp(c);
        for (auto& j : tmp) cin >> j;
        for (int j = 0; j < c; j++) {
            for (int k = j + 1; k < c; k++) {
                lIst[tmp[j]].push_back(tmp[k]);
                cnt[tmp[k]]++;
            }
        }
    }

    topological_sort();

    if (ans.size() != N) {
        cout << 0;
    }
    else {
        for (auto& i : ans) {
            cout << i << '\n';
        }
    }
}