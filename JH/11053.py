# 가장 긴 증가하는 부분 수열

# Bottom-up

import sys

N = int(sys.stdin.readline().rstrip())
list = list(map(int, sys.stdin.readline().rstrip().split()))

dp = [1] * N

for i in range(1, N):
    for j in range(i):
        if list[i] > list[j]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))
