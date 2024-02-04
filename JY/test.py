# 테스트 240115 / 2


import sys
input = sys.stdin.readline

a = map(int, input().split())
print(a)
print()
print(*a, sep="")

for i in a:
    print(i, end="")
