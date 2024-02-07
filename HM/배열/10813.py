N, M = map(int, input().split())
# N:바구니 개수
# M: 공 바꾸는 횟수
arr = [0]*N
for i in range(N):
    arr[i] = i+1

for i in range(M):
    i, j = map(int, input().split())
    arr[i-1], arr[j-1] = arr[j-1], arr[i-1]
for i in range(N):
    print(arr[i], end=" ")
