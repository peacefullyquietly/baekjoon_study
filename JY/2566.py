import sys
input = sys.stdin.readline

matrix = []
for i in range(9):
    tmp = list(map(int, input().split()))
    matrix.append(tmp)

max = 0
i, j = 0, 0
for y in range(len(matrix)):
    for x in range(len(matrix)):
        if matrix[y][x] > max:
            max = matrix[y][x]
            i = y
            j = x

print(max)
print(i+1, j+1)
