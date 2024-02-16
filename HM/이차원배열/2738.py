N, M = map(int, input().split())
A = []
B = []


for i in range(N):
    A.append(list(map(int, input().split())))

for i in range(M):
    B.append(list(map(int, input().split())))
for i in range(N):
    for j in range(M):
        print(A[i][j]+B[i][j], end=' ')
    print()
