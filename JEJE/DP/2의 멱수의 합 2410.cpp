// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
const int MAX = 1000001, MOD = 1000000000;
int N, dp[MAX];

int main()
{
     cin >> N;
     dp[1] = 1;
     dp[2] = 2;
     for(int i = 3; i <= N; i++)
     {
        if(i%2==0) dp[i] = (dp[i-1]+dp[i/2]) % MOD;
        else dp[i] = dp[i-1];
     }
     cout << dp[N] << '\n';
}