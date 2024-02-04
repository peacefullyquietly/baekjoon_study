import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    numerator = 1   # 분자
    denominator = 1  # 분모
    for i in range(M, M-N, -1):
        numerator *= i
    for i in range(N, 0, -1):
        denominator *= i
    print(int(numerator/denominator))
