// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct Info{
    int tm;
    vector<int> fr;
};Info v[501];
int dp[501];

int dfs(int n)
{
    if (dp[n] != 0) return dp[n];
    int maxim = 0;
    for(auto &i : v[n].fr) maxim = max(maxim, dfs(i));
    dp[n] = maxim + v[n].tm;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, n;
    cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        cin >> n;
        v[i].tm = n;
        while(1)
        {
            cin >> n;
            if(n == -1) break;
            v[i].fr.push_back(n);
        }
    }

    for(int i = 1; i <= tc; i++) cout << dfs(i) << '\n';
}