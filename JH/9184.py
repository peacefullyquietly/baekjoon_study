# 신나는 함수 실행
import sys
memo = {}


def w(a, b, c):
    # 기저 조건: a, b, c가 0 이하일 경우 1을 반환
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    # 기저 조건: a, b, c가 20을 초과할 경우 w(20, 20, 20)을 반환
    if a > 20 or b > 20 or c > 20:
        key = (20, 20, 20)
        if key not in memo:
            memo[key] = w(*key)
        return memo[key]

    # 기저 조건: a < b < c인 경우의 계산
    if a < b < c:
        key1 = (a, b, c-1)
        key2 = (a, b-1, c-1)
        key3 = (a, b-1, c)

        if key1 not in memo:
            memo[key1] = w(*key1)
        if key2 not in memo:
            memo[key2] = w(*key2)
        if key3 not in memo:
            memo[key3] = w(*key3)

        return memo[key1] + memo[key2] - memo[key3]

    key4 = (a-1, b, c)
    key5 = (a-1, b-1, c)
    key6 = (a-1, b, c-1)
    key7 = (a-1, b-1, c-1)

    if key4 not in memo:
        memo[key4] = w(*key4)
    if key5 not in memo:
        memo[key5] = w(*key5)
    if key6 not in memo:
        memo[key6] = w(*key6)
    if key7 not in memo:
        memo[key7] = w(*key7)

    return memo[key4] + memo[key5] + memo[key6] - memo[key7]


def main():
    while True:
        a, b, c = map(int, sys.stdin.readline().rstrip().split())
        if a == b == c == -1:
            break

        result = w(a, b, c)
        print(f"w({a}, {b}, {c}) = {result}")


if __name__ == "__main__":
    main()
