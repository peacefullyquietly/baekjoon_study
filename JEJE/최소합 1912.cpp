// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
using namespace std;

int main()

{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, answer = -1001, a[100001], dp[100001]={0};
    cin >> tc;
    for (int i = 0; i < tc; i++) cin >> a[i];
    for (int i = 0; i < tc; i++)
    {
        if (i != 0)dp[i] = max(dp[i - 1] + a[i], a[i]);
        else dp[i] = a[i];
        answer = max(dp[i], answer);
    }
    cout << answer << '\n';
    return 0;
}