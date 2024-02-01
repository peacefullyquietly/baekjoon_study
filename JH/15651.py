# N과 M(3)
import sys


def backtracking(N, M, stack):
    global start
    if len(stack) == M:
        print(' '.join(map(str, stack)))
        return

    for i in range(start, N+1):
        stack.append(i)
        backtracking(i+1, M, stack)
        stack.pop()


N, M = map(int, sys.stdin.readline().rstrip().split())
result = []
start = 1
backtracking(N, M, result)
