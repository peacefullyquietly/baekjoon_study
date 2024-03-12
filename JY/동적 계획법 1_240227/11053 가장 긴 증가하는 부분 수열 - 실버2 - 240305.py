import sys
input = sys.stdin.readline


def get_subsequence(n):
    global dp
    for i in range(n):
        for j in range(i):
            if A[i] > A[j]:
                dp[i] = max(dp[i], dp[j] + 1)
                # print(f'dp[i] = max({dp[i]}, {dp[j] + 1})')
    return max(dp)


N = int(input())
A = list(map(int, input().split()))
dp = [1 for _ in range(N)]
print(get_subsequence(N))
