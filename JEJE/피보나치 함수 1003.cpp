// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
int dp[41];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 2; i <= 41; i++)dp[i] = dp[i-1]+dp[i-2];
    cin >> n;
    while(cin >> n)
    {
        cout << dp[n] << ' ' << dp[n+1];
        cout << '\n';
    }
    //for(int i = 0; i <= 41; i++)cout << dp[i] << ' ' << dp[i+1] << '\n';
}