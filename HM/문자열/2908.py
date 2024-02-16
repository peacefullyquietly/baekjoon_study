# a,b= input().split()
# a= a[::-1]
# b= b[::-1]
# if a>b:
#     print(a)
# else:
#     print(b)

a,b= input().split()
a= list(a)
b= list(b)
a.reverse()
b.reverse()

if a>b:
    a=''.join(a)
    print(a)
else:
    b=''.join(a)
    print(b)
