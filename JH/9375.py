# 패션왕 신해빈
import sys

N = int(sys.stdin.readline().rstrip())


def combination(clothes):
    result = 1

    for v in clothes.values():
        result *= (len(v) + 1)

    return result - 1


for i in range(N):
    dress = {}
    n = int(sys.stdin.readline())
    if n != 0:
        for x in range(n):
            a, b = sys.stdin.readline().rstrip().split()
            if b not in dress:
                dress[b] = [a]
            else:
                dress[b].append(a)
        print(combination(dress))
    else:
        print(0)
