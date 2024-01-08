import sys

input = sys.stdin.readline
N, B = list(map(str, input().split()))
B = int(B)

b_list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
result = 0
for i in range(1, len(N)+1):
    sum = b_list.index(N[-i]) * (B ** (i-1))
    result += sum
print(result)
