// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
using namespace std;
const int MAX = 1001;
int dp[MAX][MAX];
string a, b;

void print(int i, int j)
{
    if(dp[i][j] == 0) return;
    if(a[i-1] == b[j-1]){
        print(i-1, j-1);
        cout << a[i-1];
    }
    else return dp[i-1][j] > dp[i][j-1]?print(i-1, j):print(i, j-1);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            char ca = a[i-1];
            char cb = b[j-1];
            if(ca == cb) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
    print(a.size(), b.size());
    cout << '\n';
}