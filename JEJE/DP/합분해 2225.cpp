// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define MAX 201
#define MOD 1000000000
using namespace std;
int dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int j = 1; j <= k; j++) dp[1][j] = j;
    for(int i = 2; i <= n; i++) for(int j = 1; j <= k; j++)
    {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
        dp[i][j] %= MOD;
    }
    cout << dp[n][k] << '\n';
}