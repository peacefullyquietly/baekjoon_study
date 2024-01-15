# 피보나치 함수
import sys


fibonacci = [(1, 0), (0, 1)]

n = int(sys.stdin.readline().rstrip())
for i in range(n):
    x = int(sys.stdin.readline().rstrip())
    for i in range(len(fibonacci), x+1):            # 이미 만들어진 요소 일 경우 중복 방지
        fibonacci.append((fibonacci[i-1][0] + fibonacci[i-2][0],
                          fibonacci[i-1][1] + fibonacci[i-2][1]))
    print(*fibonacci[x])
