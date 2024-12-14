// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
#define MAX 16
using namespace std;
int k, n, m, dp[MAX][MAX];

int main()
{
    int ky = 1, kx = 1, ans = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    dp[1][1] = 1;
    if(k > 0)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        {
            cnt++;
            if(cnt == k)
            {
                ky = i;
                kx = j;
            }
        }
        for(int i = 1; i <= ky; i++) for(int j = 1; j <= kx; j++)
        {
            if (i == 1 && j == 1) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        ans = dp[ky][kx];
        memset(dp, 0, sizeof dp);
        dp[ky][kx] = 1;
    }

    for(int i = ky; i <= n; i++) for(int j = kx; j <= m; j++)
    {
        if (i == ky && j == kx) continue;
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    cout << ans*dp[n][m] << '\n';
}