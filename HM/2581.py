
M= int(input())
N= int(input())
list = []
for i in range(M, N+1):
    if i==1:
        continue
    for j in range(2,i):
        if i %j ==0:
            break
    else :
        list.append(i)
    
if len(list)>0:
    print(sum(list))
    print(min(list))
else:print(-1)

