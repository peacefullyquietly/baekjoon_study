# N과 M(2)
def backtracking(N, M, start, result):
    if len(result) == M:
        print(' '.join(map(str, result)))
        return

    for i in range(start, N + 1):
        result.append(i)
        backtracking(N, M, i + 1, result)
        result.pop()


N, M = map(int, input().split())
result = []

backtracking(N, M, 1, result)
