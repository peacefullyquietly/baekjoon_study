# list = [25, 10, 5, 1]
# result = []
# T = int(input())

# for _ in range(T):
#     C = int(input())
#     a = ''
#     for i in range(len(list)):
#         a += str(C//list[i])+" "
#         C = C % list[i]
#     result.append(a)

# for i in result:
#     print(i)

T=int(input())
for _ in range(T):
    C= int(input())
    for i in [25,10,5,1]:
        print(C//i,end=" ")
        C%=i