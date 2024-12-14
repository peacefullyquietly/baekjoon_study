#include<iostream>
#define MAX 1001
using namespace std;
int arr[MAX][3];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, ans = MAX*MAX+1;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for(int i = 0; i < 3; i++)
    {
        int dp[MAX][3];
        for(int j = 0; j < 3; j++) dp[0][j] = MAX*MAX+1;
        dp[0][i] = arr[0][i];
        for(int j = 1; j < n; j++)
        {
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + arr[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + arr[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + arr[j][2];
        }
        for(int j = 0; j < 3; j++) if(i != j) ans = min(ans, dp[n-1][j]);
    }
    cout << ans << '\n';
}