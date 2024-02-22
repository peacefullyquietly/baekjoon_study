import sys
N = int(sys.stdin.readline())
arr =list(map(int,sys.stdin.readline().split()))
dic = { num:0 for num in arr}
M = int(sys.stdin.readline())
arr2 = list(map(int,sys.stdin.readline().split()))


result=[]


for i in arr2:
    if i in dic:
       
        result.append(1)
            
    else: result.append(0)
        
print(" ".join(str(i) for i in result))