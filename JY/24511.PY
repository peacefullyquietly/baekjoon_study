import sys
from collections import deque

input = sys.stdin.readline
queuestack = deque()
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
M = int(input())
C = list(map(int, input().split()))
"""
도현이는 길이 $M$의 수열 $C$를 가져와서 
수열의 원소를 앞에서부터 차례대로 queuestack에 삽입할 것이다. 
이전에 삽입한 결과는 남아 있다. (예제 $1$ 참고)
queuestack에 넣을 원소들이 주어졌을 때, 해당 원소를 넣은 리턴값을 출력하는 프로그램을 작성해보자.
"""
"""for i in range(M):
    x = C[i]
    for j in range(N):
        # 0이면 큐, 1이면 스택
        if A[j] == 0:
            B[j], x = x, B[j]
    print(x, end=" ")
"""
"""for i in range(N):
    queuestack1.append(B[i])

cnt = 0
for i in range(M):
    x = C[i]
    j = 0
    while j < N:
        if cnt % 2 == 0:
            # 0이면 큐, 1이면 스택
            if A[j] == 1:
                pass
            else:
                queuestack2.append(x)
                x = queuestack1.popleft()
        else:
            # 0이면 큐, 1이면 스택
            if A[j] == 1:
                queuestack1.append(x)
                queuestack2.popleft()
            else:
                queuestack1.append(x)
                x = queuestack2.popleft()
        j += 1
    cnt += 1
    print(x, end=" ")
"""
"""for i in range(M):
    x = C[i]
    for j in range(N):
        # 0이면 큐, 1이면 스택
        if A[j] == 0:
            # B[j], x = x, B[j]
            queuestack.append(x)
            x = queuestack.popleft()
        else:
            queuestack.append(x)
            queuestack.popleft()
    print(x, end=" ")"""


for j in range(N):
    # 0이면 큐, 1이면 스택
    if A[j] == 0:
        queuestack.append(B[j])

for i in C:
    queuestack.appendleft(i)
    print(queuestack.pop(), end=" ")
