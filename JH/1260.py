# DFS와 BFS
from collections import defaultdict, deque
import sys

N, M, V = map(int, sys.stdin.readline().rstrip().split())

graph = defaultdict(set)

for i in range(M):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].add(b)
    graph[b].add(a)


def DFS(start):
    visited = set()
    stack = [start]

    while stack:
        vertex = stack.pop()

        if vertex not in visited:
            visited.add(vertex)
            print(vertex, end=" ")

            stack.extend(sorted(graph[vertex] - visited, reverse=True))


def BFS(start):
    visited = set([start])
    queue = deque([start])

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")

        nbr = sorted(graph[vertex] - visited)
        for i in nbr:
            visited.add(i)
            queue.append(i)


DFS(V)
print()
BFS(V)
