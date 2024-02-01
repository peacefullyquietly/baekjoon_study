# 옥상 정원 꾸미기
import sys
n = int(sys.stdin.readline())
buildings = [int(sys.stdin.readline()) for _ in range(n)]

stack = []
result = 0

for b in buildings:
    while stack and stack[-1] <= b:
        stack.pop()
    stack.append(b)

    # result = b를 볼 수 있는 건물의 수
    result += len(stack) - 1

print(result)
