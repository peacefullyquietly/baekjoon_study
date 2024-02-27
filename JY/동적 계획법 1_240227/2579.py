import sys

input = sys.stdin.readline

# 계단 오르기 규칙
# 1. 한 번에 1 또는 2 계단 씩 => 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
# 2. 연속된 세 개의 계단을 모두 밟으면 X. 단, 시작점은 계단에 포함되지 않는다.
# 3. 마지막 도착 계단은 반드시 밟아야 함


"""def up_stairs(stairs_num):
    global dp
    i = 0
    flag1, flag2 = False, False
    finish = False
    while not finish:
        if i >= stairs_num-3:
            return dp
        elif not flag1 and not flag2:
            if dp[-1] + scores[i] + scores[i+1] >= max(dp[-1] + scores[i+1] + scores[i+2], dp[-1] + scores[i] + scores[i+2]):
                flag1 = True
                dp.append(dp[-1] + scores[i] + scores[i+1])
                i += 1
            else:
                flag2 = True
                dp.append(max(dp[-1] + scores[i+1] + scores[i+2],
                              dp[-1] + scores[i] + scores[i+2]))
                i += 2
        elif flag1:
            flag1 = False
            flag2 = True
            dp.append(max(dp[-1] + scores[i+1] + scores[i+2],
                          dp[-1] + scores[i] + scores[i+2]))
            i += 2
        elif flag2:
            flag1 = True
            flag2 = False
            dp.append(dp[-1] + scores[i] + scores[i+1])
            i += 1
        if i >= stairs_num:
            finish = True
"""


def up_stairs(N):
    if N == 1:
        print(scores[1])
    elif N == 2:
        print(scores[1]+scores[2])
    else:
        dp[1] = scores[1]
        dp[2] = scores[1]+scores[2]
        dp[3] = max(scores[1]+scores[3], scores[2]+scores[3])
        for i in range(4, N+1):
            dp[i] = max(dp[i-3]+scores[i-1] + scores[i], dp[i-2]+scores[i])
        print(dp[N])


N = int(input())
scores = [0]
for i in range(N):
    score = int(input())
    scores.append(score)
dp = [0 for i in range(301)]

up_stairs(N)
