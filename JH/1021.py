# 회전하는 큐
from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
positions = list(map(int, sys.stdin.readline().rstrip().split()))

queue = deque(range(1, N + 1))

count = 0

for p in positions:
    while True:
        left_count = queue.index(p)
        right_count = len(queue) - queue.index(p)

        if left_count <= right_count:
            queue.rotate(-left_count)
            count += left_count
        else:
            queue.rotate(right_count)
            count += right_count

        if queue[0] == p:
            queue.popleft()
            break

print(count)
