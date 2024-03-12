import sys
input = sys.stdin.readline

# 유클리드 호제법으로 최대공약수 구하기


def Euclidean(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


A, B = map(int, input().split())
print(A*B//Euclidean(A, B))
