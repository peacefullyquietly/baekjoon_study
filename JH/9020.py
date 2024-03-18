# 골드바흐의 추측

import sys

# 소수를 구하는 함수


def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):  # 제곱근까지만 확인하여 소수 여부를 판별
        if num % i == 0:
            return False
    return True


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline().strip())
    for i in range(n // 2, 1, -1):  # n의 절반부터 역순으로 탐색
        # 현재 값과 n-i가 모두 소수이면 골드바흐 파티션!
        if is_prime(i) and is_prime(n - i):
            print(i, n - i)
            break
