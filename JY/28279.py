import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
my_deque = deque()
for i in range(N):
    tmp = list(map(int, input().split()))
    len_my_deque = len(my_deque)
    if tmp[0] == 1:
        my_deque.appendleft(tmp[1])
    elif tmp[0] == 2:
        my_deque.append(tmp[1])
    elif tmp[0] == 3:
        if len_my_deque != 0:
            print(my_deque.popleft())
        else:
            print(-1)
    elif tmp[0] == 4:
        if len_my_deque != 0:
            print(my_deque.pop())
        else:
            print(-1)
    elif tmp[0] == 5:
        print(len_my_deque)
    elif tmp[0] == 6:
        if len_my_deque == 0:
            print(1)
        else:
            print(0)
    elif tmp[0] == 7:
        if len_my_deque != 0:
            print(my_deque[0])
        else:
            print(-1)
    elif tmp[0] == 8:
        if len_my_deque != 0:
            print(my_deque[-1])
        else:
            print(-1)
