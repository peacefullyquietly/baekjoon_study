# 구간 합 구하기 4
import sys


def arithmetic_progression_sum(S, A):
    S[0] = 0  # 초기값 설정

    # 누적 합 계산
    for i in range(1, len(A) + 1):
        S[i] = S[i - 1] + A[i - 1]


a, b = map(int, sys.stdin.readline().rstrip().split())
arr = list(map(int, sys.stdin.readline().rstrip().split()))
S = [0] * (len(arr) + 1)

arithmetic_progression_sum(S, arr)

for i in range(b):
    start, end = map(int, sys.stdin.readline().rstrip().split())
    print(S[end] - S[start - 1])
