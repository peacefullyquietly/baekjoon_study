# 떡 먹는 호랑이

import sys


def fibonacci(n):
    # 초기값 설정
    a, b = 1, 1
    # n번째 피보나치 수까지 계산
    for _ in range(3, n + 1):
        a, b = b, a + b
    return b


if __name__ == "__main__":
    # 입력 받기
    d, k = map(int, sys.stdin.readline().split())

    # 초기값 설정
    a, b = 1, 1
    # d번째 피보나치 수열까지 계산
    for _ in range(4, d + 1):
        a, b = b, a + b

    # a, b 값을 이용하여 계산
    ac = 1
    bc = 0
    while True:
        tmp = k - a * ac
        if tmp < 0:
            break

        if tmp % b == 0:
            bc = tmp // b
            break

        ac += 1

    # 결과 출력
    print(ac)
    print(bc)
