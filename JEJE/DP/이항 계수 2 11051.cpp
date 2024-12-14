#include<iostream>
using namespace std;
int dp[1001][1001];

int comb(int n, int r)
{
    if(dp[n][r] > 0) return dp[n][r];
    if(r == 0 || n == r) return 1;
    if(r > n-r) return comb(n, n-r);
    dp[n][r] = (comb(n-1,r)+comb(n-1,r-1))%10007;
    return dp[n][r];
}

int main()
{
    ios_base::sync_with_stido(0);cin.tie(0);
    int n, r;
    cin >> n >> r;
    cout << comb(n, r) << '\n';
}