"""import sys

input = sys.stdin.readline
# N개의 창문, N명의 사람
N = int(input())

windows = [False for i in range(N+1)]
step = 1
while step <= N:
    for i in range(step, N, step):
        windows[i] = not windows[i]
    # print(windows)
    step += 1

ans = 0
for i in range(N):
    if windows[i]:
        ans += 1
print(ans)
"""

n = int(input())
print(int(n**(1/2)))
