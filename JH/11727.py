# 2 x n 타일링 2

n = int(input())

dp = [0] * 1001

dp[0] = 1
dp[1] = 1


def DP(N):
    if dp[N]:
        return dp[N]

    for i in range(2, N+1):
        dp[i] = dp[i-2] * 2 + dp[i-1]

    return dp[N] % 10007


print(DP(n))
