# RGB 거리
import sys
N = int(sys.stdin.readline().rstrip())
number = [list(map(int, sys.stdin.readline().rstrip().split()))
          for _ in range(N)]


def DP(N):
    dp = [[0]*3 for _ in range(N)]
    dp[0] = number[0]
    for x in range(1, N):
        for i in range(3):
            if i == 2:
                dp[x][i] = min(dp[x-1][0] + number[x][i],
                               dp[x-1][1] + number[x][i])
            elif i == 1:
                dp[x][i] = min(dp[x-1][0] + number[x][i],
                               dp[x-1][2] + number[x][i])
            else:
                dp[x][i] = min(dp[x-1][1] + number[x][i],
                               dp[x-1][2] + number[x][i])

    return min(dp[-1])


print(DP(N))
