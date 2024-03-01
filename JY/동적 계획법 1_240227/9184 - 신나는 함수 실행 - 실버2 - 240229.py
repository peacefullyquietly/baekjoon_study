import sys
input = sys.stdin.readline


def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:  # 종료조건
        return 1
    elif a > 20 or b > 20 or c > 20:  # a, b, c 중 20이 넘는게 있으면
        return 1048576
    elif a < b and b < c:  # a < b < c이면

        return 2**a
    else:  # a >= b 거나 b >= c인경우 일로오는듯
        if a == b:
            return 2**a
        if a == c:
            return 2**a
        if str(a)+str(b)+str(c) not in memo:
            memo[str(a)+str(b)+str(c)] = w(a-1, b, c) + \
                w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return memo[str(a)+str(b)+str(c)]


# 약간 느리긴한데 이거도 답임
"""def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:  # 종료조건
        return 1
    elif a > 20 or b > 20 or c > 20:  # a, b, c 중 20이 넘는게 있으면
        return 1048576
    elif a < b and b < c:  # a < b < c이면

        return 2**a
    else:  # a >= b 거나 b >= c인경우 일로오는듯
        if a == b:
            return 2**a
        if a == c:
            return 2**a
        if str(a)+str(b)+str(c) not in memo:
            memo[str(a)+str(b)+str(c)] = w(a-1, b, c) + \
                w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return memo[str(a)+str(b)+str(c)]"""

while True:
    memo = {}
    cnt = 0
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1:
        break
    else:
        ans = w(a, b, c)
        print(f'w({a}, {b}, {c}) = {ans}')
        # print(cnt)
