import sys

n = int(sys.stdin.readline())
result=0

for j in range(i+1, n):
    for k in range(j+1,  n+1):
            result+=1
result= result* (n(n+1)/2-7)        
print(result)
print(3)

#몬냐 몬냐