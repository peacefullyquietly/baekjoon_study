// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int v[15][15];
    memset(v[0], 1, sizeof v[0]);
    for(int i = 1; i < 15; i++)memset(v[i], 0, sizeof v[i]);
    int tc, k, n;
    cin >> tc;
    for(int i = 1; i < 15; i++)v[0][i] = i;
    for(int i = 1; i < 15; i++)v[i][1] = 1;
    while(tc--)
    {
        cin >> k >> n;
        if(v[k][n] > 0) cout << v[k][n];
        else
        {
            for(int i = 1; i <= k; i++){
                for(int j = 2; j <= n; j++)
                {
                    v[i][j] = v[i-1][j] + v[i][j-1];
                }
            }
            cout << v[k][n];
        }
        cout << '\n';
    }
}