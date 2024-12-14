#include<iostream>
using namespace std;
const int MAX = 101;

int dp[MAX][100001];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, K;
    int W[MAX], V[MAX]; // 무게, 가치
    cin >> tc >> K;
    for(int i = 1; i <= tc; i++) cin >> W[i] >> V[i];
    for(int i = 1; i <= tc; i++){ //물품의 개수
        for(int j = 1; j <= K; j++){ //무게의 종류
            if(j-W[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[tc][K] << '\n';
}