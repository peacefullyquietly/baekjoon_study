# 2 x n 타일링

# Top-down
import sys
n = int(sys.stdin.readline().rstrip())

dp = [0] * 1001

dp[1] = 1
dp[2] = 2


def top_down(n):
    if dp[n]:
        return dp[n]

    for i in range(3, n+1):
        # dp[i] = top_down(i-1) + top_down(i-2)
        dp[i] = (top_down(i-1) + top_down(i-2)) % 10007

    return dp[n]


print(top_down(n))
