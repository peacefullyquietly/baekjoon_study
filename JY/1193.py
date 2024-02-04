import sys
input = sys.stdin.readline
N = int(input())

line = 1
while N > line:
    N -= line
    line += 1

if line % 2 == 0:   # 짝수인 경우
    a = N
    b = line - N + 1
elif line % 2 == 1:  # 홀수인 경우
    a = line - N + 1
    b = N

print(f"{a}/{b}")
