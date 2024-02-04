import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
S = set()
for i in range(N):
    tmp = input()
    S.add(tmp.rstrip())

cnt = 0
M_list = []
for i in range(M):
    tmp = input()
    M_list.append(tmp.rstrip())

for i in M_list:
    if i in S:
        cnt += 1
print(cnt)
