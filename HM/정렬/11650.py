
N = int(input())
list=[]
for i in range(N):
    x, y = map (int, input().split())
    list.append([y, x])
    
list.sort()


for i in list:
        i.reverse()
        print(" ".join(str(j) for j in i ))