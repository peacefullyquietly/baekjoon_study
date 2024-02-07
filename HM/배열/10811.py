N, M = map(int, input().split())
arr = [i for i in range(1, N+1)]
for _ in range(M):
    i, j = map(int, input().split())
    for __ in range(j-i//2):
        arr[i], arr[j-i] = arr[j-i], arr[i]


for i in range(N):
    print(arr[i], end=" ")
N, M = map(int, input().split())
arr = [i for i in range(1, N+1)]
for _ in range(M):
    i, j = map(int, input().split())
    temp = arr[i-1:j]
    temp.reverse()
    arr[i-1:j] = temp


for i in range(N):
    print(arr[i], end=" ")
