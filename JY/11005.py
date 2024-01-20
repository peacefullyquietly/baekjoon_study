import sys
input = sys.stdin.readline

alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
N, B = list(map(int, input().split()))

arr = []
while N > 0:
    arr.append(N % B)
    N //= B

for i in range(len(arr)-1, -1, -1):
    print(alphabet[arr[i]], end="")
