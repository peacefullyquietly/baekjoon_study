import sys
left = list(input())
right = []
N = int(input())
for _ in range(N):
    com = sys.stdin.readline()[:-1]
    if 'P' in com:
        com = com.split()
        left.append(com[-1])
    elif com == 'D' and len(right) != 0: 
        left.append(right.pop())
    elif com == 'L' and len(left) != 0:
        right.append(left.pop())
    elif com == 'B' and len(left) != 0:
        del left[-1]
right.reverse()
print("".join(left + right))