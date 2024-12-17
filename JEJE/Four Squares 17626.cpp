// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

int n;
int dp[50001];

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cin >> n;
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[1] + dp[i - 1];
        for (int j = 2; j * j <= i; j++)
        {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }

    cout << dp[n];
}