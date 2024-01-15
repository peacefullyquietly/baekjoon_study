# 파도반 수업
import sys
N = int(sys.stdin.readline().rstrip())

dp = [0, 1, 1, 1] + [0]*97
for _ in range(N):
    a = int(sys.stdin.readline().rstrip())

    if dp[a]:
        print(dp[a])
        continue
    for i in range(4, a+1):
        dp[i] = dp[i-2] + dp[i-3]

    print(dp[i])
