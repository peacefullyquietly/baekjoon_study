#include<iostream>
#include<string>
#define MAX 101
using namespace std;
string a, b, c;
int dp[MAX][MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> c;
    for(int i = 1; i <= a.size(); i++) for(int j = 1; j <= b.size(); j++) for(int k = 1; k <= c.size(); k++)
    {
        char ca = a[i-1], cb = b[j-1], cc = c[k-1];
        if(ca == cb && cb == cc) dp[i][j][k] = dp[i-1][j-1][k-1]+1;
        else dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k], dp[i][j][k-1]));
    }
    cout << dp[a.size()][b.size()][c.size()] << '\n';
}