import sys
input = sys.stdin.readline

N = int(input())
dp = [0 for i in range(N+2)]
dp[1] = 0
dp[2] = 1
for i in range(2, N+1):
    dp[i] = dp[i-1] + 1
    if i % 6 == 0:
        dp[i] = min(dp[i//3], dp[i//2]) + 1
    elif i % 2 == 0:
        # dp[i//2] + 1이 dp[i]보다 작으면 변경.
        dp[i] = min(dp[i], dp[i//2] + 1)
    elif i % 3 == 0:
        # dp[i//3] + 1이 dp[i]보다 작으면 변경.
        # 위에 i % 2 부분에서 변경됐으면 바뀐거랑 또 비교하게 됨
        dp[i] = min(dp[i], dp[i//3] + 1)

print(dp[N])
