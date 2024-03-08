import sys
input = sys.stdin.readline


def get_continuous_sum(n):
    dp[0] = nums[0]
    for i in range(1, n):
        if nums[i] > dp[i-1] + nums[i]:
            dp[i] = nums[i]
        else:
            dp[i] = dp[i-1] + nums[i]

    print(max(dp[0:n+1]))


N = int(input())
dp = [-1001 for i in range(100001)]
nums = list(map(int, input().split()))

if N == 1:
    print(nums[0])
else:
    get_continuous_sum(N)
