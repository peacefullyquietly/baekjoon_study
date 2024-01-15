# 연속합

import sys
n = int(sys.stdin.readline().rstrip())

number = list(map(int, sys.stdin.readline().rstrip().split()))


def DP(number):
    dp = [-1000]*(n+1)
    dp[1] = number[0]

    for i in range(2, n+1):
        dp[i] = max(number[i-1], dp[i-1] + number[i-1])

    return dp


print(max(DP(number)))
