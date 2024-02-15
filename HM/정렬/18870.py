N = int(input())
arr=list(map(int, input().split()))
result=[]

for i in range(N):
    count=0
    for j in range(N):
        if arr[j]<arr[i]:
            count+=1
    result.append(count)
    
print(" ".join(str(i) for i in result))
            