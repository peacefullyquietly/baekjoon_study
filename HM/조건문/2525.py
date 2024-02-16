A, B = input().split()
A = int(A)
B = int(B)
C = int(input())

H = C//60
M = C % 60


if B > 60-M:  # 60분을 넘어갈 떄
    if A+H > 23:  # 자정을 넘어갈 떄
        A = A+H-23
        B += M
    else:
        A += H
        B += M
        print(A, B)
