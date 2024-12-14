k = int(input())
a=[0 for _ in range(10001)]
dp=[0 for _ in range(10001)]
for i  in range(k):
    n = int(input())
    a[i] = n

dp[0] = a[0]
dp[1] = a[0]+a[1]
dp[2] = max(a[0]+a[2], a[1]+a[2])
for i in range(3,k):
    dp[i] = max(a[i]+dp[i-2], a[i]+a[i-1]+dp[i-3])
print(dp[k-1])