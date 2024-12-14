# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
from collections import deque
visit = [0 for _ in range(1001)]
mat = [[0 for _ in range(1001)] for _ in range(1001)]
N = 0
def dfs(v):
    print(v, end= ' ')
    visit[v] = 1
    for i in range(1, N+1):
        if visit[i] == 1 or mat[v][i] == 0:
            continue
        dfs(i)

def bfs(v):
    q = deque([])
    q.appendleft(v)
    visit[v] = 1
    while q:
        v = q[-1]
        print(q.pop(), end=' ')
        for i in range(1, N+1):
            if visit[i] == 1 or mat[v][i] == 0:
                continue
            q.appendleft(i)
            visit[i] = 1


# print(mat)
N, M, V = list(map(int, input().split()))
for _ in range(M):
    X, Y = list(map(int, input().split()))
    mat[X][Y] = mat [Y][X] = 1 
dfs(V)
print()
visit = [0 for _ in range(1001)]
bfs(V)
