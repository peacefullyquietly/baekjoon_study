import sys
input = sys.stdin.readline

N = int(input())

tmp = 1
initial = 3
for i in range(1, N):
    tmp = tmp * 2
    initial += tmp

print(initial**2)
