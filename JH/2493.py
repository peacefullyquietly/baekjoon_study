# 탑
import sys
n = int(input())

tower = []
stack = []
dp = [0] * n

for x, y in enumerate(list(map(int, sys.stdin.readline().rstrip().split()))):
    tower.append([x, y])

stack.append(tower[0])
for i in range(1, n):
    while stack and stack[-1][1] < tower[i][1]:
        stack.pop()
    if len(stack) > 0:
        dp[i] = stack[-1][0] + 1
    stack.append(tower[i])

print(*dp)
