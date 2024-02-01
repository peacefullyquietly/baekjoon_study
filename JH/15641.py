# N과 M(1)
def backtracking(N, M, result, visited):
    if len(result) == M:
        print(' '.join(map(str, result)))
        return

    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            result.append(i)
            backtracking(N, M, result, visited)
            result.pop()
            visited[i] = False


N, M = map(int, input().split())
visited = [False] * (N + 1)
result = []

backtracking(N, M, result, visited)
