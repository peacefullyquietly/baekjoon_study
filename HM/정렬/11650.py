N = int(input())
list=[]
for i in range(N):
    x, y = map (int, input().split())
    list.append([x, y])
    
    
list.sort()

for i in list:

        print(" ".join(str(j) for j in i))