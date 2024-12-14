// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
using namespace std;
int dp[1001][1001];
string a, b;

// void print(int x, int y)
// {
//     if(dp[y-1][x] > 0){
//         if(dp[y-1][x] != dp[y][x]) cout << a[y-1];
//         print(x, y-1);
//     }else if(dp[y][x-1] > 0){
//         if(dp[y][x-1] != dp[y][x]) cout << a[y-1];
//         print(x-1, y);
//     }return;
// }

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            char na = a[i-1];
            char nb = b[j-1];
            if(na == nb) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // print(b.size(), a.size());
    // cout << '\n';
    cout << dp[a.size()][b.size()] << '\n';
}