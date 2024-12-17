// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define MAX 10001
using namespace std;
int s, k;
int coin[MAX], dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s >> k;
    for(int i = 1; i <= s; i++) cin >> coin[i];
    dp[0] = 1;
    for(int i = 1; i <= s; i++) for(int j = coin[i]; j <= k; j++) dp[j] += dp[j-coin[i]]; //현재 i원을 제외하고 있는 금액을 만들수 있는 경우의수
    cout << dp[k] << '\n';
}