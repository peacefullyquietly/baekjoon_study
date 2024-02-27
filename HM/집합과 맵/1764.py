import sys
N, M = map(int, sys.stdin.readline().split())

setN = set()
setM= set()

for i in range(N):
    name = sys.stdin.readline().rstrip()
    setN.add(name)
    
for i in range(M):
    name = sys.stdin.readline().rstrip()
    setM.add(name)
    
result = sorted(setN&setM)

print(len(result))
for i in result:
    print(i)