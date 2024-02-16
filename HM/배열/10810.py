N,M= map(int, input().split()) 
# N:바구니 개수
# M:공을 던질 횟수
arr=[0] *N

for _ in range(M):
    i,j,k =map(int, input().split())
    for a in range(i-1,j):
        arr[a]=k

for _ in range(N):
    print(arr[_], end=" ")

