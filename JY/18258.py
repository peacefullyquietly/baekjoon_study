import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
queue = deque()
for i in range(N):
    tmp = list(map(str, input().split()))
    len_queue = len(queue)
    if tmp[0] == "push":
        queue.append((int(tmp[1])))
    elif tmp[0] == "pop":
        if len_queue == 0:
            print(-1)
        else:
            print(queue.popleft())
    elif tmp[0] == "size":
        print(len(queue))
    elif tmp[0] == "empty":
        if len_queue == 0:
            print(1)
        else:
            print(0)
    elif tmp[0] == "front":
        if len_queue == 0:
            print(-1)
        else:
            print(queue[0])
    elif tmp[0] == "back":
        if len_queue == 0:
            print(-1)
        else:
            print(queue[-1])
