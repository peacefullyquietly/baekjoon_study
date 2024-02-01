# 홀수
import sys
number = [int(sys.stdin.readline().rstrip()) for _ in range(7)]

result = []
for i in number:
    if i % 2 != 0:
        result.append(i)

if not result:
    print(-1)
else:
    print(sum(result), min(result), sep="\n")
