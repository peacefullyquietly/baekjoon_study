table = [[0 for i in range(100)] for j in range(100)]
N = int(input())

for _ in range(N):
    a, b = map(int, input().split())
    for i in range(a, a+10):
        for j in range(b, b+10):
            table[i][j] = 1
# print(table.count(1))
counts = 0
for row in table:
    counts += row.count(1)
print(counts)
