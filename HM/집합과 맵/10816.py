import sys
dic={}
result=[]
N = int(sys.stdin.readline())
num = list(map (int, sys.stdin.readline().split()))
for i in num:
    dic[i]=0
for i in num:
    dic[i]+=1

M = int(sys.stdin.readline())
num2 = map (int, sys.stdin.readline().split())
for i in num2:
    if i in dic:
        result.append(dic[i])
    else: result.append(0)
print(" ".join(str(i) for i in result))


# 다양한 풀이 공부하기