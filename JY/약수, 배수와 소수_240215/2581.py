"""# 첫 시도

M = int(input())
N = int(input())

ans = set()
for i in range(M, N+1):
    for j in range(2, i):
        if i % j == 0:
            break
    else:
        if i != 1:
            ans.add(i)
if len(ans) > 0:
    print(sum(ans))
    print(min(ans))
else:
    print(-1)"""

# 정답 확인 후, 탐색시간 줄여보기 시도
import math
M = int(input())
N = int(input())

ans = set()
for i in range(M, N+1):
    for j in range(2, int(math.sqrt(i))+1):
        if i % j == 0:
            break
    else:
        if i != 1:
            ans.add(i)
if len(ans) > 0:
    print(sum(ans))
    print(min(ans))
else:
    print(-1)
