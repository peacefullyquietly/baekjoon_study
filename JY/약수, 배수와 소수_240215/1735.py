import sys
input = sys.stdin.readline

# 분자, 분모
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

# 유클리드 호제법으로 최대공약수 구하기


def Euclidean(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


c1, c2 = (a2*b1 + a1*b2), a2*b2
gcd = Euclidean(c1, c2)
print(c1 // gcd, c2 // gcd)
