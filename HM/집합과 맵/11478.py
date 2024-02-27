import sys
result=set()
S = sys.stdin.readline().rstrip()
for i in range(len(S)):# 0-4
    for j in range(i,len(S)):
        result.add(S[i:j+1])
        
print(len(result))


# 잘 못하겠음 