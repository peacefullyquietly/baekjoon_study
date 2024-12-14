// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> rgb(1001, vector<int>(3, 0));
    vector<vector<int>> dp(1001, vector<int>(3, 0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int i = 0;  i < tc; i++)
    {
        int cost;
        for (auto &j : rgb[i])
        {
            cin >> cost;
            j = cost;
        }
    }
    dp[0] = rgb[0];
    
    for (int i = 1; i < tc; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1])+rgb[i][2];
    }
    cout << min(dp[tc-1][0], min(dp[tc-1][1], dp[tc-1][2]));
}