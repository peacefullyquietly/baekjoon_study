// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
using namespace std;
int dp[4001][4001];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a, b;
    int ans = 0;
    cin >> a >> b;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            char na = a[i-1];
            char nb = b[j-1];
            if(na == nb) dp[i][j] = dp[i-1][j-1]+1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';

}