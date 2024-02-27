import sys
N, M = map(int, sys.stdin.readline().split())

setN = set()
setM= set()


setN=set(list(map(int, sys.stdin.readline().split())))
setM=set(list(map(int, sys.stdin.readline().split())))

    
print(len(setN-setM)+len(setM-setN))