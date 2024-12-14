// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
const int MAX = 10001, INF = 100001;
int n, k, dp[MAX], coin[MAX];

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= k; i++) dp[i] = INF;
    //for(auto &i : dp) cout << i; 
    for(int i = 1; i <= n; i++) cin >> coin[i];
    for(int i = 1; i <= n; i++) for(int j = coin[i]; j <= k; j++) dp[j] = min(dp[j], dp[j-coin[i]]+1);
    if(dp[k] == INF) cout << -1;
    else cout << dp[k];
    cout << '\n';
}