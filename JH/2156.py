# 포도주 시식

import sys
n = int(sys.stdin.readline().rstrip())
wine = [0] + [int(sys.stdin.readline().rstrip()) for _ in range(n)]


def max_wine(wine):
    dp = [0]*(n+1)
    dp[1] = wine[1]

    if n > 1:
        dp[2] = wine[1] + wine[2]

    for i in range(3, n+1):
        dp[i] = max(dp[i-4] + wine[i-1] + wine[i],
                    max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]))

    return max(dp)


print(max_wine(wine))
