#include<iostream>
#define MAX 501
#define INF ~(1u << (sizeof(int) * 8 - 1));
using namespace std;
int sum[MAX], matrix[MAX][20], dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> matrix[i][0] >> matrix[i][1];
    }
    
    for (int i = 1; i < tc; i++)
    {
        for (int j = 1; i + j <= tc; j++)
        {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i+j] = min(dp[j][i+j], 
                                 dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
            }
        }
    }
    cout << dp[1][tc];
}