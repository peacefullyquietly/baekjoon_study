#include<iostream>
using namespace std;
const int MAX = 100001;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int len, card[2][MAX]= {{0},{0}}, dp[2][MAX] = {{0},{0}};
        cin >> len;
        for(int i = 1; i <= len; i++)cin >> card[0][i];
        for(int i = 1; i <= len; i++)cin >> card[1][i];
        dp[0][1] = card[0][1];
        dp[1][1] = card[1][1];
        for(int i = 2; i <= len; i++)
        {
            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + card[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + card[1][i];
        }
        cout << max(dp[0][len], dp[1][len]) << '\n';
    }
}

