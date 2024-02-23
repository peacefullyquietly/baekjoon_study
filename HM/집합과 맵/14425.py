import sys 


N, M = map(int, sys.stdin.readline().split())
S={}
count=0
for i in range(N):
    a = sys.stdin.readline()
    S[a]=0
for i in range(M):
    ss = sys.stdin.readline()
    if ss in S:
        count+=1
print(count)