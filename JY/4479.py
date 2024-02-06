import sys
input = sys.stdin.readline


def cantor(N):
    if N == 1:
        return "-"
    left = cantor(N // 3)
    center = " " * (N // 3)
    return left + center + left


while True:
    try:
        N = int(input())
        ans = cantor(3**N)
        print(ans)
    except:
        break
