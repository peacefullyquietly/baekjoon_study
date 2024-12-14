# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
from collections import deque
MAX = 1001
visited = [False] * MAX
graph = [[] for _ in range(MAX)]


def dfs(node):
    visited[node] = True
    print(node, end=' ')
    for i in graph[node]:
        if not visited[i]:
            dfs(i)

def bfs(start_node):
    q = deque([])
    q.appendleft(start_node)
    visited[start_node] = True
    while q:
        node = q.pop()
        print(node, end=' ')
        for i in graph[node]:
            if not visited[i]:
                q.appendleft(i)
                visited[i] = True


if __name__ == "__main__":
    N, M, V = map(int, input().split())
    for _ in range(M):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    for i in graph:
        i.sort()
    dfs(V)
    print()
    visited = [False] * MAX
    bfs(V)
    print()
