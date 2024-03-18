# 돌 게임 2
# 다시 풀어봐야할듯...ㅠㅠ

# 입력
n = int(input())

# DP
if n == 1:
    print('CY')
elif n == 2:
    print('SK')
elif n == 3:
    print('CY')
else:
    dp = [-1] * (n+1)
    dp[1] = 'CY'    # 창영이 이김
    dp[2] = 'SK'    # 상근이 이김
    dp[3] = 'CY'    # 창영이 이김

    for i in range(4, n+1):
        # 돌이 1개 혹은 3개 남은 상황일 때
        if dp[i-1] == 'CY' or dp[i-3] == 'CY':
            dp[i] = 'SK'
        else:
            dp[i] = 'CY'
    print(dp[n])
