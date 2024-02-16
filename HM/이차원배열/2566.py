table = [list(map(int, input().split())) for i in range(9)]
max = 0
row = 0
col = 0

for i in range(9):
    for j in range(9):
        if max <= table[i][j]:
            max = table[i][j]
            row = i+1
            col = j+1
            
print(max)

print(row, col)
