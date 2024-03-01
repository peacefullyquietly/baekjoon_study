import sys
input = sys.stdin.readline

# 이게 dp가 맞나?


def Padovan_sequence(n):
    P[1] = 1
    P[2] = 1
    for i in range(3, n):
        P[i] = P[i-3] + P[i-2]


T = int(input())
P = [0 for i in range(101)]
Padovan_sequence(101)
for i in range(T):
    N = int(input())
    print(P[N])
