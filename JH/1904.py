# 01타일

import sys
n = int(sys.stdin.readline().rstrip())


dp = [0, 1, 2] + [0]*(n-2)

for i in range(3, n+1):
    dp[i] = dp[i-1] + dp[i-2]

    if dp[i] >= 15746:
        dp[i] %= 15746

print(dp[n])
