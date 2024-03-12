# 평범한 베낭
'''
5 7
2 4
4 3
1 1
8 9
1 10
answer:17
output:15
'''
import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
backpack = [list(map(int, sys.stdin.readline().rstrip().split()))
            for _ in range(N)]

backpack.sort()

dp = [[0]*2] * N
dp[0] = [backpack[0][0], backpack[0][1]]

for i in range(1, N):
    for j in range(i):
        if backpack[i][0] + dp[j][0] <= K:

            dp[i] = max(dp[i], [backpack[i][0]+dp[j]
                        [0], backpack[i][1] + dp[j][0]], key=lambda x: x[0])
        else:
            dp[i] = [backpack[i][0], backpack[i][1]]
# print("dp:", dp)
result = max(dp, key=lambda x: x[1])
print(result[1])
