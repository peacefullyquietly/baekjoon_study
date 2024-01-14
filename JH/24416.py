# 알고리즘 수업 - 피보나치 수 1
import sys
n = int(sys.stdin.readline().rstrip())
DP_count = 0

recursion_dp = [0]*5 + [5, 8] + [0]*34


def recursion(n):
    if recursion_dp[n]:
        return recursion_dp[n]

    if n == 5 or n == 6:
        return recursion_dp[n]

    recursion_dp[n] = recursion(n-1) + recursion(n-2)

    return recursion_dp[n]


# dp table init
dp = [0]*(n+1)


def DP(n):                  # Bottom-up
    global DP_count
    dp[1] = dp[2] = 1
    for i in range(3, n+1):         # 3~n 까지 (n-3) + 1 번 실행됨
        DP_count += 1
        dp[i] = dp[i-1] + dp[i-2]

    return DP_count


print(recursion(n), DP(n))
