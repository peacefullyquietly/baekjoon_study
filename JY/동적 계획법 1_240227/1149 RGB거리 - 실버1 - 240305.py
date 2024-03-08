import sys
input = sys.stdin.readline


# 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값

# 1번 집의 색은 2번 집의 색과 달라야 함
# N번 집의 색은 N-1번 집의 색과 달라야 함 (2번 집의 색은 1번 집의 색과 달라야 함)
# i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다. (위 아래로 달라야 함)


"""def paint_house(n):
    global dp
    global dp_idx
    if n == 1:
        dp[1] = min(houses[0])
    else:

        dp[1] = min(houses[0])
        dp_idx[1] = houses[0].index(min(houses[0]))
        pre_idx = -1
        for k in range(2, n+1):
            for i in range(0, 3):
                if dp_idx[k-1] != i:
                    if dp[k] > dp[k-1] + houses[k-1][i]:
                        if dp[k] > dp[k-1] + houses[k-1][i]:
                            dp[k] = dp[k-1] + houses[k-1][i]
                            pre_idx = i
                        else:
                            pre_idx = i
                dp_idx[k] = pre_idx
            print(pre_idx)
        print(dp)
"""


def paint_house(n):
    global dp
    dp[0][0] = houses[0][0]
    dp[0][1] = houses[0][1]
    dp[0][2] = houses[0][2]
    for i in range(1, n):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + houses[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + houses[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + houses[i][2]
    return min(dp[N-1])


N = int(input())
houses = []
for i in range(N):
    # 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어짐
    rgb = list(map(int, input().split()))
    houses.append(rgb)
dp = [[1000 for _ in range(3)] for i in range(N)]

print(paint_house(N))
print(dp)
