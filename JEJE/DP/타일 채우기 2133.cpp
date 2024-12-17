// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
int dp[31];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i-2] * 3;
        for(int j = 0; j < i-2; j += 2)
        {
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[n] << '\n';
}