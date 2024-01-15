import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    zero, one = 1, 0  # f(1)일 때 0과 1
    n = int(input())
    for j in range(n):
        # n의 0과 1은 각각 n-1의 1의 호출, n-1의 0과 1의 호출의 합
        zero, one = one, zero + one
    print(zero, one)
