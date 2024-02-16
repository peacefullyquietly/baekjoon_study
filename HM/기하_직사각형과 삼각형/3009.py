# A= map(int, input().split())
# B= map(int, input().split())
# C= map(int, input().split())
# D=[]
# for i in range(1):
#     if A[i]==B[i]:
#         D.append(C[i])
#     elif A[i]==C[i]:
#         D.append(B[i])
#     else: D.append(A[i])

# print(D)

A= list(map(int, input().split()))
B= list(map(int, input().split()))
C= list(map(int, input().split()))
D=[]


for i in range(2):
    
    if A[i]==B[i]:
        D.append(C[i])
    elif A[i]==C[i]:
        D.append(B[i])
    else: D.append(A[i])

print(" ".join(str(i) for i in D))

#flkjlkjfds