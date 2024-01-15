# 1,2,3 더하기
import sys
N = int(sys.stdin.readline().rstrip())

dp = [0]*11


def top_down(n):
    if dp[n]:
        return dp[n]
    if n == 1 or n == 2:
        return n
    elif n == 3:
        return n+1

    dp[n] = top_down(n-1) + top_down(n-2) + top_down(n-3)
    return dp[n]


for i in range(N):
    print(top_down(int(sys.stdin.readline().rstrip())))
