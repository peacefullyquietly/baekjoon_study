// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
bool v[1000001][5];
bool ans[5];
int tc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    pair<int, int> day = { 0,1 };
    int studnet_cnt = 0;

    cin >> tc;

    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }

    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
            if (k == j) continue;
            int flag = 0;
            for (int i = 0; i < tc; i++) {
                if (v[i][j] && v[i][k]) flag++;
                if (studnet_cnt < flag) {
                    studnet_cnt = flag;
                    day = { j, k };
                }
            }
        }
    }
    ans[day.first] = 1;
    ans[day.second] = 1;

    cout << studnet_cnt << "\n";
    for (bool& i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}