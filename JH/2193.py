# 이친수

import time
startTime1 = time.time()


# Bottom-up
n = int(input())

dp = [0] * 91
dp[1] = 1
dp[2] = 1


def pinary_number(N):
    if dp[n] != 0:
        return dp[n]

    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n]


print(pinary_number(n))
endTime1 = time.time() - startTime1
print("bottom_up:", endTime1)


startTime2 = time.time()
# Top-down
dp1 = [0]*91
dp1[1] = 1
dp1[2] = 1


def top_down(n):
    if dp1[n] != 0:
        return dp1[n]

    dp1[n] = top_down(n-1) + top_down(n-2)
    return dp1[n]


print(top_down(n))
endTime2 = time.time() - startTime2

print("top_down:", endTime2)
