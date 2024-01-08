import sys
input = sys.stdin.readline

matrix = []
max_len = 0
for i in range(5):
    tmp = input().rstrip()
    matrix.append(list(tmp))
    if len(tmp) > max_len:
        max_len = len(tmp)

for i in range(5):
    if len(matrix[i]) < max_len:
        cnt = max_len-len(matrix[i])
        while cnt != 0:
            matrix[i].append("")
            cnt -= 1

for x in range(len(matrix[0])):
    for y in range(len(matrix)):
        print(matrix[y][x], end="")
