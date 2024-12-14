A, N = map(int,input().split())
goon = []
for i in range(46):
    for j in range(i):
        goon.append(i)
goon = goon[A-1:N]
print(sum(goon))