import sys
input = sys.stdin.readline

a1, a0 = list(map(int, input().split()))
c = int(input())
n0 = int(input())

"""
f(n) = 7n + 7, 
g(n) = n, c = 8, 
n0 = 1이다. 
f(1) = 14, c × g(1) = 8이므로 O(n) 정의를 만족하지 못한다.

f(n) = 7n + 7, 
g(n) = n, c = 8, 
n0 = 10이다.
모든 n ≥ 10에 대하여 7n + 7 ≤ 8n 이므로 O(n) 정의를 만족한다.
"""

# O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다}


def isBigO_n(a1, a0, c, n0):
    if a1 * n0 + a0 <= c * n0 and a1 <= c:
        return 1
    else:
        return 0


print(isBigO_n(a1, a0, c, n0))
