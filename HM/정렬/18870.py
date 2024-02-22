# import sys
# N = int(input())
# arr=list(map(int, sys.stdin.readline().split()))
# idx_arr=sorted(list(set(arr)))

# count=0
# for i in idx_arr:
#     for j in range(N):
#         if i==arr[j]:
#             arr[j]=count
            
#     count+=1 
# print(" ".join(str(i) for i in arr))
  

# import sys
# N = int(input())
# arr=list(map(int, sys.stdin.readline().split()))
# idx_arr=sorted(list(set(arr)))


# for i in arr:
#     print(idx_arr.index(i),end=" " )


import sys
N = int(input())
arr=list(map(int, sys.stdin.readline().split()))
idx_arr=sorted(list(set(arr)))


dic ={idx_arr[i]: i for i in range(len(idx_arr)) }
print(dic)
for i in arr:
    print(dic[i], end=' ')