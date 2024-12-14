// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
#define MAX 101
#define bMAX (1 << 10)-1
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;
ll N, ans = 0, dp[MAX][10][1<<10];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int j = 1; j <= 9; j++) dp[1][j][1 << j] = 1;
    for(int i = 2; i <= N; i++) for(int j = 0; j <= 9; j++) for(int k = 0; k <= bMAX; k++)
    {
        if (j == 0) dp[i][0][k | (1 << 0)] += dp[i - 1][1][k] % MOD;
        else if (j == 9) dp[i][9][k | (1 << 9)] += dp[i - 1][8][k] % MOD;
        else dp[i][j][k | (1 << j)] += (dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k]) % MOD;
    }
    for(int j = 0; j <= 9; j++)
    {
        ans += dp[N][j][bMAX];
        ans %= MOD;
    }
    cout << ans << '\n';
}