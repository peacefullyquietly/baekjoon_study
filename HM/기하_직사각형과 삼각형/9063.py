N = int(input())
x =[]
y=[]
for i in range(N):
    arr=list(map(int, input().split()))
    x.append(arr[0])
    y.append(arr[1])
    
print((max(x)-min(x))*(max(y)-min(y)))

    
    