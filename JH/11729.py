# 하노이 탑
import sys


def move(N, start, end):
    print(start, end)


def hanoi_tower(N, start, end, sub):
    if N == 1:
        move(1, start, end)
        return
    else:
        hanoi_tower(N-1, start, sub, end)
        move(N, start, end)
        hanoi_tower(N-1, sub, end, start)


n = int(sys.stdin.readline().rstrip())
print(2**n-1)
hanoi_tower(n, 1, 3, 2)
