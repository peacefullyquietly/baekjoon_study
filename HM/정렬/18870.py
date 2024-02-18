import sys
N = int(input())
arr=list(map(int, sys.stdin.readline().split()))
idx_arr=sorted(list(set(arr)))

# count=0
# for i in orderd:
#     for j in range(N):
#         if i==arr[j]:
#             arr[j]=count
            
#     count+=1 
        

# print(" ".join(str(i) for i in arr))

# for i in arr:
#     print(orderd.index(i),end=" " )
         
dic ={idx_arr[i]: i for i in range(len(idx_arr)) }
# 999: 0
# 1000:1
for i in arr:
    print(dic[i], end=' ')