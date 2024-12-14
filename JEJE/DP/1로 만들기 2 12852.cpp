#include<iostream>
#define MAX 1000001
using namespace std;

int N, dp[MAX], tracker[MAX];

int DDP()
{
    dp[1] = 0;
    for(int i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1]+1;
        tracker[i] = i-1;
        if(i % 3 == 0 && dp[i/3]+1 < dp[i])
        {
            dp[i] = dp[i/3]+1;
            tracker[i] = i/3;
        }
        if(i % 2 == 0 && dp[i/2]+1 < dp[i])
        {
            dp[i] = dp[i/2]+1;
            tracker[i] = i/2;
        }
    }
    return dp[N];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    DDP();
    cout << dp[N] << '\n';
    int n = N;
    while(n != 0)
    {
        cout << n << ' ';
        n = tracker[n];
    }
}