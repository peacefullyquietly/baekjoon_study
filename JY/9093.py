N = int(input())

min_x = 11111
min_y = 11111
max_x = -11111
max_y = -11111
for i in range(N):
    x, y = list(map(int, input().split()))
    if x > max_x:
        max_x = x
    if y > max_y:
        max_y = y
    if x < min_x:
        min_x = x
    if y < min_y:
        min_y = y

print((max_x-min_x)*(max_y-min_y))
