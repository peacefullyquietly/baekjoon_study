# 약수 구하기

N , K = map(int, input().split())

count = 0 # 약수 순서

for i in range(1, N+1):

    if N%i==0:
        count+=1
    if count==K:
        print(i)
        break
else: print(0)


# 다른 풀이
arr=[]
N, K = map(int, input().split())

for i in range(1, N + 1):
    if N % i == 0:
        arr.append(i)


if K > len(arr):
    print(0)
else:
    print(arr[K-1])