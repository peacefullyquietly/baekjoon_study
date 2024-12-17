// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define MAX 2001
using namespace std;
int s, v[MAX];
bool dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    for(int i = 1; i <= s; i++) cin >> v[i];
    
    for(int i = 1; i <= s; i++)dp[i][i] = true;  
    for(int i = s; i >= 1; i--) for(int j = i+1; j <= s; j++)
    {
        if(v[i] == v[j] && (i+1 == j || dp[i+1][j-1])) dp[i][j] = true;
    }

    // for(int i = 1; i <= s; i++){
    //     for(int j = 1; j <= s; j++) cout << dp[i][j];
    //     cout << '\n';
    // } 

    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}