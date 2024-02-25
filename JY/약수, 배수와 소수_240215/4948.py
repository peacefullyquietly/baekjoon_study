import sys

input = sys.stdin.readline
flag = True
N = 123456
N *= 2
primeList = [True] * (2*N + 1)
primeList[0] = False
# 에라토스테네스의 체 응용
maxNum = int(N ** 0.5)
# 자연수 N이 주어졌을 때, N보다 크고, 2N보다 작거나 같은 소수의 개수를 구하는 프로그램
for i in range(2, maxNum + 1):
    if primeList[i-1] == True:
        for j in range(i+i, N+1, i):
            primeList[j-1] = False
while flag:
    a = int(input())
    if a == 0:
        flag = False
        break
    else:
        ans = 0
        for j in range(a+1, 2*a+1):
            if primeList[j-1] == True:
                ans += 1
        print(ans)
