import sys
import math
input = sys.stdin.readline
t = int(input())

for _ in range(t):
    n = int(input())
    i = n
    flag = True
    while flag:
        for j in range(2, int(math.sqrt(i))+1):
            if i % j == 0:
                break
        else:
            if i > 1 and i >= n:
                print(i)
                flag = False
                break
        i += 1
