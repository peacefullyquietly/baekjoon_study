// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

unsigned dp[31][31];

unsigned fill_dp(unsigned n, unsigned r)
{
    if (dp[n][r] > 0) return dp[n][r];
    else if (n == r || r == 0) return 1;
    else dp[n][r] = fill_dp(n - 1, r) + fill_dp(n - 1, r - 1);
    return dp[n][r];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned n, m;
    cin >> n;
    while (cin >> n >> m) cout << fill_dp(m, n) << '\n';
}