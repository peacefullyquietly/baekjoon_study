# 전깃줄

n = int(input())
lists = []
dp = [1]*n

for i in range(n):
    a, b = map(int, input().split())
    lists.append([a, b])

lists.sort()

for i in range(1, n):
    for j in range(0, i):

        # if문에 해당할 경우 교점이 생기지 않음
        if lists[j][1] < lists[i][1]:
            dp[i] = max(dp[i], dp[j]+1)
            # dp[i] = 교점이 생기지 않는 최대 길이

# 제거해야하는 전깃줄 = 전체 줄의 개수 - 교점이 생기지 않는 최대 길이
print(n-max(dp))
# print("dp:", dp)
