# 계단 오르기
import sys


def max_score(n, scores):
    dp = [0] * (n + 1)

    dp[1] = scores[1]

    for i in range(2, n + 1):
        dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] +
                    scores[i - 1] + scores[i])

    return dp[n]


n = int(sys.stdin.readline().rstrip())
stair_score = [0] + [int(sys.stdin.readline().rstrip()) for _ in range(n)]

print(max_score(n, stair_score))
