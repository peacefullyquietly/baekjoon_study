# 바이러스

from collections import defaultdict, deque
import sys

computer = int(sys.stdin.readline().rstrip())
connect = int(sys.stdin.readline().rstrip())

graph = defaultdict(set)

# 노드 생성
for i in range(connect):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].add(b)
    graph[b].add(a)


def virus(start):
    worm_virus = []
    visited = set([start])

    queue = deque([start])

    while queue:
        vertex = queue.popleft()
        worm_virus.append(vertex)

        nbr = graph[vertex] - visited

        for v in nbr:
            visited.add(v)
            queue.append(v)

    return worm_virus


print(len(virus(1))-1)
