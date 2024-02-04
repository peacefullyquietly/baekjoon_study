# N과 M(4)
import sys
a, b = map(int, sys.stdin.readline().rstrip().split())


def backtracking(N, M, stack, start):
    if len(stack) == M:
        print(' '.join(map(str, stack)))
        return

    for i in range(start, N+1):
        stack.append(i)
        backtracking(N, M, stack, i)
        stack.pop()


result = []
start = 1
backtracking(a, b, result, start)
