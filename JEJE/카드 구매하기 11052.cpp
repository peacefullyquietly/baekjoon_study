// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>

using namespace std;

vector<int> P(1,0);
int dp[1001];
int main()
{
    int n, packc;
    cin >> packc;
    while(cin >> n) P.push_back(n);
    for(int i = 1; i <= packc; i++){
        for(int j = 0; j < i; j++)
        {
            dp[i]=max(dp[i],dp[j]+P[i-j]);
        }
    }
    cout << dp[packc] << '\n';
}