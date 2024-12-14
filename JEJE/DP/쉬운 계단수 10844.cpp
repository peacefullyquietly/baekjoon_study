// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
#define MAX 101
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;
ll n, ans = 0, dp[MAX][10];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int j = 1; j <= 9; j++) dp[1][j] = 1;
    dp[1][0] = 0;
    for(int i = 2; i <= n; i++) for(int j = 0; j <= 9; j++)
    {
        if(j == 0)dp[i][j] += dp[i-1][j+1]%MOD;
        else if(j == 9)dp[i][j] += dp[i-1][j-1]%MOD;
        else dp[i][j] += (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
    }
    
    // for(auto &i : dp) {
    //     for(auto &j : i) cout << j << ' ';
    //     cout << '\n';
    // }
    
    for(int j = 0; j <= 9; j++)
    {
        ans += dp[n][j];
        ans %= MOD;
    }
    cout << ans << '\n';
}