N = int(input())
arr = [N]
count = 0
arr = input().split()
V = int(input())
for i in range(N):
    print(arr[i])
    if arr[i] == V:
        count=count+1
print(count)
