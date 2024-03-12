# 퇴사
import sys
n = int(input())
consulting = []

# dp[i] = i일에 상담을 한다고 가정했을 때 얻을 수 있는 최대 비용
dp = [0]*15
# cost = 0
current_index = 0

for _ in range(n):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    consulting.append((a, b))


def DP(x):
    global consulting
    global current_index

    current_index += x
    # 상담 소요 일자가 퇴사일을 초과한 경우
    if current_index + consulting[x][0] > n:
        return 0

    for i in range(n):
        dp[i] = consulting[i][1] + DP(consulting[i][0])


print(DP[0])
