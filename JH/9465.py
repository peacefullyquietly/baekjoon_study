# 스티커
'''
반례
2
4
17 100 62 41
56 65 16 70
253     # ans:226
6
44 40 8 55 75 51
67 53 77 67 86 67
393    # ans:376
'''

import sys


def max_sticker_score(n, stickers):
    dp = [[0] * n for _ in range(3)]  # 3행 n열의 2차원 배열로 동적 계획법을 위한 배열 생성

    # 첫 번째 열은 각 스티커의 점수로 초기화
    dp[0][0] = stickers[0][0]
    dp[1][0] = stickers[1][0]
    dp[2][0] = 0

    # 두 번째 열부터 동적 계획법을 이용하여 최대 점수 계산
    for i in range(1, n):
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + stickers[0][i]  # 이전 스티커를 뗀 경우
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + stickers[1][i]  # 이전 스티커를 뗀 경우
        dp[2][i] = max(dp[0][i-1], dp[1][i-1], dp[2][i-1])  # 이전 스티커를 떼지 않은 경우

    # 마지막 열에서의 최대값이 최종 최대 점수
    return max(dp[0][-1], dp[1][-1], dp[2][-1])


# 테스트 케이스 개수 입력
T = int(input())

# 각 테스트 케이스에 대해 최대 점수 출력
for _ in range(T):
    n = int(input())
    stickers = []
    for _ in range(2):
        stickers.append(list(map(int, sys.stdin.readline().rstrip().split())))
    print(max_sticker_score(n, stickers))
