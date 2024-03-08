import sys

input = sys.stdin.readline

# 계단 오르기 규칙
# 1. 한 번에 1 또는 2 계단 씩 => 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
# 2. 연속된 세 개의 계단을 모두 밟으면 X. 단, 시작점은 계단에 포함되지 않는다.
# 3. 마지막 도착 계단은 반드시 밟아야 함


def up_stairs(n):
    # dp 1, 2, 3인 경우 밑의 3줄의 동작만 할 것임
    # 마지막 도착 계단은 반드시 밟음
    dp[1] = scores[1]
    dp[2] = scores[1]+scores[2]
    dp[3] = max(scores[1]+scores[3], scores[2]+scores[3])
    # N이 4이상인경우 for문 동작
    for i in range(4, N+1):
        dp[i] = max(dp[i-3]+scores[i-1] + scores[i], dp[i-2]+scores[i])
    print(dp[N])


N = int(input())
scores = [0 for i in range(301)]
for i in range(1, N+1):
    scores[i] = int(input())
# dp에는 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 저장
dp = [0 for i in range(301)]   # 계단의 개수는 300이하의 자연수

up_stairs(N)
# print(dp)
