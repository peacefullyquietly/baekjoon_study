import sys
input = sys.stdin.readline


def fib(n):
    """a, b = 1, 1  # f(1), f(2)
    for i in range(3, n+1):
        a, b = b, a+b
    return b"""

    # 바텀-업 (좀 더 안전한 방식)
    """for i in range(2, N+1) :
            dp[i] = dp[i-2] + dp[i-1] # 반복문을 이용하여 아래서부터 값을 채워가는 방식
    """
    # 탑-다운
    if dp[n] != -1:  # 기존에 계산한 부분의 문제는 재계산하지 않고 리턴
        return dp[n]
    # 메모이제이션 : 구한 값을 바로 리턴하지 않고 dp 테이블에 저장 후 리턴
    dp[n] = fib(n-2) + fib(n-1)
    return dp[n]


def fibonacci(n):
    return n - 2


n = int(input())
dp = [-1]*(n+1)
dp[0] = 0
dp[1] = 1
print(fib(n), fibonacci(n))
