
N, B = input().split(" ")
B = int(B)
N=N[::-1]

number = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
result = 0
for i in range(len(N)):
    sum = B**i * number.index(N[i])
    result += sum
print(result)
