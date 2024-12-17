# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
y, x = map(int, input().split())
grid = []
for i in range(y):
    grid.append(list(input()))

# for i in grid:
#     print(i)

for i, arr in enumerate(grid):
    check = -1
    for j, word in enumerate(arr):
        if word == 'c':
            check = 0
        if check == -1:
            grid[i][j] = -1
        if check >= 0:
            grid[i][j] = check
            check += 1

for i in grid:
    print(" ".join(list(map(str,i))))

        