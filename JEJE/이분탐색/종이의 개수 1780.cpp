// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;
int p[2187][2187], bottom = 0, mid = 0, top = 0;

int line(int x, int y, int size)
{
    int want = p[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++)
        {
            if (want != p[i][j]) return 18;
        }
    }
    return want;
}
void dfs(int x, int y, int size)
{
    int num = line(x, y, size);
    if (num == -1)  bottom += 1;
    else if (num == 0) mid += 1;
    else if (num == 1) top += 1;
    else {
        for (int i = x; i < x + size; i += size / 3) {
            for (int j = y; j < y + size; j += size / 3) {
                dfs(i, j, size / 3);
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int size, n;
    cin >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            cin >> p[i][j];
        }
    }
    dfs(0, 0, size);
    cout << bottom << '\n' << mid << '\n' << top << '\n';
}